#include "skey_gen.c"
#include "vkey_gen.c"

int main (int argc, char** argv)
{
    if (argc != 3) printf("Incorrect main function arguments");

    int t = 0, l = 0;
    t = atoi (argv[1]);
    l = atoi (argv[2]);

    FILE* Input_parametrs = NULL;
    Input_parametrs = fopen("PARAMS.txt", "r");
    if (Input_parametrs == NULL) printf ("Error of open PARAMS.txt");

    unsigned long int p_ = 0, q_ = 0;
    fscanf(Input_parametrs, "%lu %lu", &p_, &q_);
     
    skey_gen (p_, q_, t, l);
    vkey_gen (p_, q_, t, l);


    fclose (Input_parametrs);
    return 0;
}
