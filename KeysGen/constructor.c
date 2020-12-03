#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#include "functions.c"
#include "main_key_gen.c"
#include "skey_gen.c"
#include "vkey_gen.c"
#include "pkey_gen.c"

int main (int argc, char** argv)
{
    if (argc != 1) printf("Incorrect main function arguments");

    int t = 0, l = 0;
    //t = atoi (argv[1]);
    //l = atoi (argv[2]);
    scanf ("%d", &t);
    scanf ("%d", &l);

    FILE* Input_parametrs = NULL;
    Input_parametrs = fopen("PARAMS.txt", "r");
    if (Input_parametrs == NULL) printf ("Error of open PARAMS.txt");

    unsigned long int p_ = 0, q_ = 0;
    fscanf(Input_parametrs, "%lu %lu", &p_, &q_);
    fclose (Input_parametrs);

    main_key_gen (p_, q_, t, l);
    skey_gen (p_, q_, t, l);
    vkey_gen (p_, q_, t, l);
    pkey_gen(p_, q_, t, l);

    return 0;
}
