#include <stdlib.h>
#include "stdio.h"
#include <math.h>
#include <time.h>
#include "KeysGen/functions.c"

//g = PK[0], first parameter from public key
//M -message which we want encrypt
//q_ p_ to count n
//c - encrypted message
main_datatype encryption(main_datatype M)
{

    //define parameters to private keys
   // main_datatype M = 0;

   // printf ("Write number for take part in lottery\n\n----  ");
  //  scanf ("%llu", &M);


    FILE* file_pkeys = NULL;
    file_pkeys = fopen ("KeysGen/PKEYS.txt", "r");
    if (file_pkeys == NULL)
    {
        printf ("\nERROR. Cannot open PKEYS file. File encryption.c\n\n");
        return;
    }

    main_datatype g = 0;
    fscanf (file_pkeys, "%llu", &g);
    fclose (file_pkeys);

    FILE* params = NULL;
    params = fopen ("KeysGen/PARAMS.txt", "r");
    if (params == NULL)
    {
        printf ("\nERROR. Cannot open PARAMS file. File encryption.c\n\n");
        return;
    }

	main_datatype p_ = 0, q_ = 0;
    fscanf (params, "%llu %llu", &p_, &q_);
    fclose (params);

    main_datatype n = 0;
    main_datatype p = 0, q = 0;
    main_datatype x = 0, c = 0;

    p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;


    //define x from Z_n^*
    x = randZ_n(p, q);

    //encrypt message
    c = (intpower(g, M, n) * intpower(x, n, n)) % (n * n);

    return c;
}
