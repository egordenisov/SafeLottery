// взять секретные ключи из файла
// написать функцию , которая находить v
// записать в файл
// l number of servers
// v -square of generator in Z_n^2
void vkey_gen(unsigned long int p_, unsigned long int q_, int t, int l)
{
    //srand(time(NULL));
    //define parameters
    unsigned long int n, p, q, m, v, delta;//parameters to private keys
    p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;
    delta = fact(l);
    //define verification key

    FILE* file_vkeys = NULL;
    file_vkeys = fopen ("VKEYS.txt", "w+");
    if (file_vkeys == NULL)
    {
        printf ("\nERROR. Cannot create VKEYS file. File vkey_gen.c\n\n");
        return;
    }

    FILE* file_skeys = NULL;
    file_skeys = fopen ("SKEYS.txt", "r");
    if (file_skeys == NULL)
    {
        printf ("\nERROR. Cannot open SKEYS file. File vkey_gen.c\n\n");
        return;
    }

    FILE* params = NULL;
    params = fopen ("PARAMS.txt", "r");
    if (params == NULL)
    {
        printf ("\nERROR. Cannot open PARAMS file. File vkey_gen.c\n\n");
        return;
    }
    fscanf (params, "%lu %lu %lu", &p_, &q_, &v);


    printf ("v = %lu; n = %lu, delta = %lu\n\n", v, n, delta);
    int i;
    unsigned long int sk = 0;
    for (i = 0; i < l; i++)
    {
        fscanf (file_skeys, "%lu", &sk);
        printf ("sk = %lu; ", sk);
        fprintf (file_vkeys, "%lu\n", (intpower(v, (delta * sk), n) % (n * n)));
        printf ("vkey = %lu\n", (intpower(v, (delta * sk), n) % (n * n)));
    }

    printf ("\nSTATUS: OK. Verification keys was generated. File vkey_gen.c\n\n");

    fclose(file_vkeys);
}
