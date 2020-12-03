#include "share_decryption.c"

int main ()
{
    printf ("Result of share_decryption = %llu;\n", share_decryption (1079, 868, 5604, 6));
    printf ("Result of share_decryption = %llu;\n", share_decryption (2388, 349, 5604, 6));
    printf ("Result of share_decryption = %llu;\n", share_decryption (925, 843, 5604, 6));
    printf ("Result of share_decryption = %llu;\n", share_decryption (3543, 652 , 5604, 6));
    printf ("Result of share_decryption = %llu;\n", share_decryption (4082, 316 , 5604, 6));
    printf ("Result of share_decryption = %llu;\n", share_decryption (4852, 287 , 5604, 6));
    //printf ("%llu\n", intdiv (6, 2, 35));


    return 0;
}
