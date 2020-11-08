#include <stdlib.h>
#include <math.h>
#include <time.h>

int randZ_n (int p, int q); //generate random numbers from Z_n^*
void pkey_gen (int p_, int q_); //generate Key

int randZ_n (int p, int q)
{
    int output = 0;
    output = rand () % (p * q);
    while ((output == p) || (output == q))
    {
        output = rand () % (p * q);
    }        
    return output;
}

void pkey_gen(int p_, int q_)
{
    srand(time(NULL));

    //define parameters to private keys
    int n = 0;
    int p = 0, q = 0;
    int m = 0, a = 0, b = 0, beta = 0;

    p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;
    m = p_ * q_;

    //define a,b from Z_n^*
    a = randZ_n(p, q);
    b = randZ_n(p, q);
    beta = randZ_n(p, q);

    //define public key
    long int PK[3] = {0, 0, 0};
    PK[0] = (long int)(powl (1 + n, a) * powl (b, n)) % (n * n);
    PK[1] = n;
    PK[2] = (a * m * beta) % n;
}

int main ()
{
    return 0;
}
