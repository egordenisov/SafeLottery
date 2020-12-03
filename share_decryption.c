#include <stdlib.h>
#include "stdio.h"
#include <math.h>
#include <time.h>
#include "KeysGen/functions.c"

//надо написать хэш-функцию hash_func
//c_i = c^(2*DELTA*s_i) (лучше сделать это вычисление  в отдельной функции, потому что его производит игрок со своим s_i)
//так что на вход подается уже c_i
//v_i = VK[i]
//видимо делается на защищенном сервере(есть s)
//r- случайное число в [0, A], пусть A = n
//x, x_ параметры для нахождения e, е параметр проверки идентичности логарифмов
//
main_datatype hash_func(main_datatype a1, main_datatype a2, main_datatype a3, main_datatype a4, main_datatype a5, main_datatype a6, main_datatype n)
{
    main_datatype c = 0;
    c = (a1 * a2) % (n * n);
    c = (c * a3) % (n * n);
    c = (c * a4) % (n * n);
    c = (c * a5) % (n * n);
    c = (c * a6) % (n * n);
    return c;
}


main_datatype share_decryption(main_datatype VK_i, main_datatype s_i, main_datatype c, int l)
{
    srand(time(NULL));

    FILE* params = NULL;
    params = fopen ("KeysGen/PARAMS.txt", "r");
    if (params == NULL)
    {
        printf ("\nERROR. Cannot open PARAMS file. File share_decription.c\n\n");
        return 0;
    }

	main_datatype p_ = 0, q_ = 0, v = 0, delta = 0;
    fscanf (params, "%llu %llu %llu", &p_, &q_, &v);
    fclose (params);

    delta = fact(l);

    //define parameters for shared decryption
    main_datatype n = 0;
    main_datatype p = 0, q = 0;
	main_datatype e = 0, e_ = 0, r = 0, x = 0, x_=0, y = 0;
    main_datatype g = 0, G = 0, h = 0, H = 0;
    main_datatype c_i = 0;
	p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;

    c_i = intpower (c, 2 * delta * s_i, n);
    printf ("c_i = %llu;\n", c_i);

    g = intpower(c, 4*delta, n);
    printf ("g = %llu;\n", g);



	r = (rand() % (n - 1)) + 1;
	x =	intpower(g, r, n);
	printf ("r = %llu;\n", r);
	printf ("----> x = %llu;\n", x);

	h = intpower(v, delta, n);
	x_= intpower(h, r, n);
	printf ("h = %llu;\n", h);
	printf ("-------->> x_ = %llu;\n", x_);

	G = (c_i * c_i) % (n * n);
	H = VK_i;
	printf ("G = %llu;\n", G);
	printf ("H = %llu;\n", H);

	e = hash_func(g, h, G, H, x, x_, n);//определяем параметр e
    printf ("\ne at the first time = %llu\n", e);

	y = (r + e * s_i) % (n * n);

    main_datatype div_num_1 = 0, div_num_2 = 0;
    div_num_2 = intdiv(  (intpower(h, y, n))  ,  (intpower(H, e, n))  ,  n  );
	printf ("-------->> We count div_num_2 = %llu\n\n", div_num_2);

	printf ("(intpower(g, y, n)) = %llu; (intpower(G, e, n)) = %llu;\n\n", (intpower(g, y, n)), (intpower(G, e, n)));
	div_num_1 = intdiv(  (intpower(g, y, n))  ,  (intpower(G, e, n))  ,  n  );
	printf ("----> We count div_num_1 = %llu\n\n", div_num_1);

	e_ = hash_func(g, h, G, H, div_num_1, div_num_2, n);

    printf ("\nwe here\n\n");

	printf ("\ne at the second time = %llu\n", e_);
	if (e == e_)
	{
		//игрок прошел проверку по секретному ключу
		printf ("Share decription OK\nc_i = %llu;\n", c_i);
		return c_i;
	}
	else
    {
		//игрок не прошел проверку по секретному ключу
		printf ("Skare decription ERROR\n");
		return 0;
	}
}
