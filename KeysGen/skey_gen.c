//l -- number of servers;t -- number of users   for decryption

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
    while (Nod(beta, n) != 1)
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

    FILE* params = NULL;
    params = fopen ("PARAMS.txt", "a");
    if (params == NULL)
    {
        printf ("ERROR. File 'PARAMS.txt' was not found. File skey_gen.c\n\n");
        return;
    }
    fprintf (params, " %lu", beta);
    fclose(params);





    FILE* file_skey = NULL;
    file_skey = fopen ("SKEYS.txt", "w+");
    if (file_skey == NULL)
    {
        printf ("\nERROR. Cannot open/create 'SKEYS.txt'. File skey_gen.c\n\n");
        return;
    }

    for (i = 0; i < l; i++)
    {
        fprintf(file_skey, "%lu\n", f_(i, a, t) % (n * m));
    }
    printf ("\nSTATUS: OK. Secret keys was generated. File skey_gen.c\n\n");

    fclose (file_skey);
    free (a);
}
