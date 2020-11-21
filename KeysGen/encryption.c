#include <stdlib.h>
#include <math.h>
#include <time.h>

int randZ_n (int p, int q); //generate random numbers from Z_n^*
void encryption(int g, int q_, int p_, int M);//encryption

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
//g = PK[0], first parameter from public key
//M -message which we want encrypt
//q_ p_ to count n 
//c - encrypted message
void encryption(int g, int q_, int p_, int M)
{
    srand(time(NULL));

    //define parameters to private keys
    int n = 0;
    int p = 0, q = 0;
    int x = 0, c = 0;
	double d;
    p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;

    //define x from Z_n^*
    x = randZ_n(p, q);
    
    //encrypt message
    //
    d = (pow(g, M) * pow(x, n));
	c = (int)d;    
    c = c % (n*n);
    
}

int main ()
{
    return 0;
}
