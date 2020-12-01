 #include "stdio.h"
 #include "stdlib.h"

unsigned long int intpower (unsigned long int a, unsigned long int b)
{
    unsigned long int i = 0, res = a;

    if (b == 0) return 1;

    for (i = 1; i < b; i++)
    {
        res = res * res;
    }

    return res;
}

unsigned long int main ()
{
      FILE* params = NULL;
      params = fopen ("PARAMS.txt", "r");
 
      unsigned long int p_, q_;
      fscanf (params, "%ld %ld", &p_, &q_);
      unsigned long int n = (2 * p_ + 1) * (2 * q_ + 1);
 
      unsigned long int* square;
      int i, j;
      unsigned long int c = 0;
      int a = 1, k = 1;
      square = (unsigned long int*) calloc(n + 1, sizeof(unsigned long int));
      for (i = 0; i <= n; i++)
      {
          square[i] = i * i;
      }
 
 
      for (i = 2; i <= n; i++)
      {
         while(intpower(square[i] , a) % (n * n) != 1)
         {
             for (j = 2; j < n; j++)
             {
                 if (intpower(square[i], a) % (n * n) == square[j])
                 {
                     k = 0;
                     break;
                 }
                 else
                 {
                     k = 1;
                 }
             }
 
             if (k == 1)
             {
                  break;
             }
             else
             {
                a = a + 1;
             }
        }
 
         if (k == 0) c = square[i];
 
 
 
      }
      free (square);
      fclose (params);

      return c;
} 
