#include "encryption.c"

int main ()
{

    printf ("Crypt number = %llu\n", encryption(33));
    printf ("Crypt number = %llu\n", encryption(289));
    printf ("Crypt number = %llu\n", encryption(445));
    printf ("Crypt number = %llu\n", encryption(1648));
    printf ("Crypt number = %llu\n", encryption(100500));
    printf ("Crypt number = %llu\n", encryption(69));

    return 0;
}
