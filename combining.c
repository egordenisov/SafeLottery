#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "stdio.h"
#include "KeysGen/functions.c"

//main_datatype mod_func, возможно понадобится, см комментарий ниже

//в этой функции делю u-1 на n на цело(см криптосистема Пэйе)
main_datatype L_func(main_datatype u, main_datatype n)
{

    main_datatype c = 0;
    c = (u-1) / n;
    return c;
}



//должен прочитать из файла t+1 ключей s_i=SK[i], у которых proof = 1, а так же их c_i=c[i](см share decryption algorithm )
//если их меньше, выдать ошибку
// без понятия как это делать, поэтому пока просто обозначил их за SK[i]
// S набор t+1 SK[i]
// t+1 необходимое количество серверов с правильным proof, мы сами задаем этот параметр
main_datatype combining(int t, int l)
{
    FILE* params = NULL;
    params = fopen ("KeysGen/PARAMS.txt", "r");
    if (params == NULL)
    {
        printf ("\nERROR. Cannot open PARAMS file. File combining.c\n\n");
        return 0;
    }

	main_datatype p_ = 0, q_ = 0;
    fscanf (params, "%llu %llu", &p_, &q_);
    fclose (params);

    FILE* pkey_file = NULL;
    pkey_file = fopen ("KeysGen/PKEYS.txt", "r");
    if (pkey_file == NULL)
    {
        printf ("\nERROR. Cannot open PKEYS file. File combining.c\n\n");
        return 0;
    }

	main_datatype pk_1 = 0, pk_2 = 0, pk_3 = 0;
    fscanf (pkey_file, "%llu %llu %llu", &pk_1, &pk_2, &pk_3);
    fclose (pkey_file);


    main_datatype delta = fact(l);

    main_datatype n = 0;
    main_datatype p = 0, q = 0;
	main_datatype j = 1, j_ = 1;
	p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;

    FILE* DATA_FROM_SERVERS = NULL;
    DATA_FROM_SERVERS = fopen ("DATA_FROM_SERVERS.txt", "r");
    if (DATA_FROM_SERVERS == NULL)
    {
        printf ("\nERROR. Cannot open DATA_FROM_SERVERS file. File combining.c\n\n");
        return 0;
    }
    main_datatype* c = NULL;
    c = (main_datatype*) calloc(l, sizeof(main_datatype));
    int i = 0;
    for (i = 0; i < l; i++)
    {
        fscanf (DATA_FROM_SERVERS, "%llu", &c[i]);
        printf ("c[%d] = %llu\n", i, c[i]);
    }
    fclose (DATA_FROM_SERVERS);


	main_datatype M;
	// определяю массив mu_0

	main_datatype mu_0j = 1;
	main_datatype MULT  = 1;

	for (j = 2; j <= (t+2); j++)
    {
        mu_0j = delta;


        for (j_ = 2; j_ <= (t+2); j_++)
        {
            if (j_ != j) mu_0j = mu_0j * ( j_ ) / (intabs(j_, j));
        }
        printf ("mu_0j = %llu\n", mu_0j);

        MULT = (MULT * intpower(c[j-1], 2 * mu_0j, n)) % (n * n);
    }
printf ("MULT = %llu\n", MULT);
    printf ("pk_3 = %llu\n", pk_3);

    M = intdiv_n (  L_func(MULT, n)  ,  4 * delta * delta * pk_3  ,  n);

	//вычисляю произведение П c_j ^(2*mu_0[j]) mod n^2(см формулу в combining algorithm 5.1)
	//результат произведения записываю в  MULT

	// теперь наконец вычисляю открытый техт M
	// правда здесь может получится нецелое число, тогда придется переписывать функцию mod_func, которая выдает остаток от деления
	// по идее она должна прибавлять к числителю дроби n, пока частное не станет целым, но я хз как это делать в си

	//расшифровано, открытый текст получен
	free (c);

	return M;
}
