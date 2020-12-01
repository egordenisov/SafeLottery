#include "stdio.h"
#include "stdlib.h"
#include "math.h"

unsigned long int intpower (unsigned long int a, unsigned long int b)
{
    unsigned long int i = 0, res = a;
 
    if (b == 0) return 1;
 
    for (i = 1; i < b; i++)
    {
         res = res * res;
    }
 
    return res;
}

//factorial
unsigned long int fact(int l)
{
    int i;
    unsigned long int factorial = 1;
    for (i = 1; i < l; i++)
    {
        factorial = factorial * (i + 1);
    }        
    return factorial;
}

// взять секретные ключи из файла
// написать функцию , которая находить v
// записать в файл
// l number of servers
// v -square of generator in Z_n^2
void vkey_gen(unsigned long int p_, unsigned long int q_, int t, int l)
{
    srand(time(NULL));
    //define parameters
    unsigned long int n, p, q, m, v, delta;//parameters to private keys
    p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;
    delta = fact(l);
    //define verification key

    FILE* file_vkeys = NULL;
    file_vkeys = fopen ("VKEYS.txt", "w+");
    if (file_vkeys == NULL) printf ("Error of create/open vkeys file");

    FILE* file_skeys = NULL;
    file_skeys = fopen ("SKEYS.txt", "r");
    if (file_skeys == NULL) printf ("Error of open skeys file");

    FILE* params = NULL;
    params = fopen ("PARAMS.txt", "r");
    if (params == NULL) printf ("Error of open param file");
    fscanf (params, "%lu %lu %lu", &p_, &q_, &v);


    int i;
    unsigned long int sk = 0;
    for (i = 0; i < l; i++)
    {
        fscanf (file_skeys, "%lu", &sk);
        fprintf (file_vkeys, "%lu\n", (intpower(v, delta * sk) % (n * n)));
    }
    fclose(file_vkeys);
}
