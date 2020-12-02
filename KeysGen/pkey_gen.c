//generate Key
void pkey_gen(unsigned long int p_, unsigned long int q_, int t, int l)
{
    //srand(time(NULL));

    //define parameters to private keys
    unsigned long int n = 0;
    unsigned long int p = 0, q = 0;
    unsigned long int m = 0, a = 0, b = 0, beta = 0, buf;

    p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;
    m = p_ * q_;

    FILE* params = NULL;
    params = fopen ("PARAMS.txt", "r");
    if (params == NULL)
    {
        printf ("ERROR. File 'PARAMS.txt' was not found. File pkey_gen.c\n\n");
        return;
    }
    fscanf(params, "%lu %lu %lu %lu", &buf, &buf, &buf, &beta);


    //define a,b from Z_n^*
    a = randZ_n(p, q);
    b = randZ_n(p, q);

    //define public key
    unsigned long int PK[3] = {0, 0, 0};
    PK[0] = (intpower (1 + n, a, n) * intpower (b, n, n)) % (n * n);
    PK[1] = n;
    PK[2] = (a * m * beta) % n;

    FILE* pkey_file = NULL;
    pkey_file = fopen ("PKEYS.txt", "w");
    if (pkey_file == NULL)
    {
        printf ("ERROR. File 'PKEYS.txt' was not found. File pkey_gen.c\n\n");
        return;
    }

    fprintf(pkey_file, "%lu\n%lu\n%lu\n", PK[0], PK[1], PK[2]);
    fclose(pkey_file);

    printf ("\nSTATUS: OK. Public keys was generated. File pkey_gen.c\n\n");
}
