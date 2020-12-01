#include "stdio.h"
#include "stdlib.h"
#include "math.h"

 int main ()
 {   
     FILE* params = NULL;
     params = fopen ("PARAMS.txt", "r");

     unsigned long int p_, q_;
     fscanf (params, "%ld %ld", &p_, &q_);
     unsigned long int n = (2 * p_ + 1) * (2 * q_ + 1);

     unsigned long int* square;
     int i, c; 
     int a,k = 1;
     square = (unsigned long int*) calloc(n, sizeof(unsigned long int));
     for (i = 1; i < n; i++)
     {   
         square[i] = i*i;
     }
     for (i = 1; i < n; i++)
     {
       while(pow(square[i],a)%(n*n) != 1)
         for (j = 1; i < n; i++)
         {
          if (pow(square[i], a)%(n*n) == square[j])
             { k = 0; break}
          else
             {k=1}
 
         if (k == 1) break;
         a = a + 1;
         }
         if (k == 0)
         {   
             c = square[j];
             break;
         }
     }
     return c;
     free square
     fclose (params);
}
