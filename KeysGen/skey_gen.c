//l -- number of servers;t -- number of users   for decryption
//дописать функцию суммы
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

unsigned long int f_(int i, unsigned long int *a, int t)
{
    
    int k;
    unsigned long int c = 0;
    for (k = 0; k < t+1; k++)
    {
        c += a[k] * pow(i, k);

    }    
    return c;
}

// хочу записать результат в вектор
void skey_gen(unsigned long int p_, unsigned long int q_, int t, int l)
{
    srand(time(NULL));
    //define parameters
    unsigned long int n = 0, p = 0, q = 0, m = 0, beta = 0;//parameters to Shamir
    p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    m = p_* q_;
    n = p * q;
    //define beta from Z_n^*
    beta = rand() % n;
    while ((beta == p)||(beta == q))
    {
        beta = rand() % n;
    }

    //define list of factors
    unsigned long int* a = NULL;
    a = (unsigned long int*) calloc(t + 1,  sizeof(unsigned long int));
    if (a == NULL) printf("Error of memory allocate");

    a[0] = beta * m;

    int i = 0;
    for (i = 1; i < (t+1); i++)
    {
	    a[i] = rand() % (n * (m - 1));
    }
    //define skey_i

    FILE* file_skey = NULL;
    file_skey = fopen ("SKEYS.txt", "w+");
    if (file_skey == NULL) printf ("Error of file"); 

    for (i = 0; i < l; i++)
    {
        fprintf(file_skey, "%lu\n", f_(i, a, t) % (n * m));
    }

    fclose (file_skey);
    free (a);
}
