//l -- number of servers;t -- number of users   for decryption
//дописать функцию суммы
unsigned f_(int *i, int *a, int *t){
    int k;
    unsigned c = 0;
    for (k=1,k<*t+1,k++)
    {
        c += *i**a;

    }    
    return c
}

// хочу записать результат в вектор
void skey_gen(int *p_, int *q_, int *t, *l){
    srand(time(NULL));
    int i;
    //define parameters
    int n, p, q, m, beta;//parameters to Shamir
    p = 2**p_ + 1;
    q = 2**q_ + 1;
    m = *p_* *q_;
    n = p*q;
    //define beta from Z_n^*
    beta = rand()%n
    while (beta == p)||(beta == q)
    {
        beta = rand()%n
    }
    //define list of factors
    int *a;
    a = (int*)malloc(t+1 * sizeof(int));
    a[0] = beta*m;
    for (i = 1; i<*t+1; i++)
    {
	a[i] = (m-1)*rand()%n;
    }
    //define skey_i
    int *SK;
    SK = (int*)malloc(*l * sizeof(int));
    for (i = 1; i<*l; i++)
    {
        SK[i] = f_(i, a, t)%(n*m);
    }
    free a;
    free SK;
    
}
