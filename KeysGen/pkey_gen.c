//generate random numbers from Z_n^*
int randZ_n(int *a,int *p, int *q){
    a = rand()%(*p**q);
    while (a == *p)||(a== *q)
    {
        a = rand()%(*p**q)
    }        
    return a
}
// хочу записать в файл
void pkey_gen(int *p_, int *q_){
    srand(time(NULL));
    int i;
    //define parameters
    int n, p, q, m, a, b, beta;//parameters to private keys
    p = 2**p_ + 1;
    q = 2**q_ + 1;
    n = p * q;
    m = p_ * q_;
    //define a,b from Z_n^*
    a = randZ_n(a, p, q);
    b = randZ_n(b, p, q);
    beta = randZ_n(beta, n, p, q);
    //define public key
    PK[3] = {0, 0, 0};
    PK[0] = pow(1+n, a)*pow(b, n)%(n*n);
    PK[1] = n;
    PK[2] = a*m*beta%n;
    
}
