#include <stdlib.h>
#include "stdio.h"
#include <math.h>
#include <time.h>
#include "KeysGen/functions.c"

main_datatype computation_block(main_datatype number_of_player)
{
    FILE* params = NULL;
    params = fopen ("KeysGen/PARAMS.txt", "r");
    if (params == NULL)
    {
        printf ("\nERROR. Cannot open PARAMS file. File computation_block.c\n\n");
        return 0;
    }
	main_datatype p_ = 0, q_ = 0;
    fscanf (params, "%llu %llu", &p_, &q_);
    fclose (params);

    FILE* crypro_data = NULL;
    crypro_data = fopen ("CRYPTO_DATA.txt", "r");
    if (crypro_data == NULL)
    {
        printf ("\nERROR. Cannot open CRYPTO_DATA file. File computation_block.c\n\n");
        return 0;
    }

	// читает из файла N зашифрованных сообщений от пользователей c[i]
	main_datatype n = 0;
    main_datatype p = 0, q = 0, i = 0;
	p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;
	main_datatype c = 1, buf = 0;

	for (i = 0; i < number_of_player; i++)
    {
        fscanf (crypro_data, "%llu", &buf);
        c = (c * buf) % (n * n);
    }
	fclose (crypro_data);

    return c;
	}
	//c и есть ответ к лотерее, надо записать его в файл
