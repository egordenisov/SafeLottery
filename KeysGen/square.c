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
//euclide algorithm
unsigned long int Nod(unsigned long int a,unsigned long int b)
{
    while (a && b)
        if (a >= b)
           a %= b;
        else
           b %= a;
    return a | b;
}
//function count coprimes
unsigned long int coprime(unsigned long int a, unsigned long int b)
{
    while(b)
    {
        a %= b;

        //swap a & b
        int temp = a;
        a = b;
        b = temp;
    }

    return a;
}
//function to count euler's totient function
unsigned long int phi(unsigned long int n)
{
    unsigned long int result = 0;
    unsigned long int k;
    for(k = 1; k <= n; k++)
        result += coprime(k, n) == 1;
    return result;
}



unsigned long int main ()
{
      FILE* params = NULL;
      params = fopen ("PARAMS.txt", "r");
 
      unsigned long int p_, q_;
      fscanf (params, "%ld %ld", &p_, &q_);
      unsigned long int n = (2 * p_ + 1) * (2 * q_ + 1);
 	  unsigned long int m = p_*q_;
      unsigned long int* square;
	  unsigned long int* n2_group;//Z_n^2
      unsigned long int i, j = 1 ;
      unsigned long int c = 0;
	  unsigned long int buf; 
      int a = 1, k = 1;

	  //заполняем массив элементов группы Z_n^2
	  n2_group = (unsigned long int*) calloc(phi(n*n), sizeof(unsigned long int));
      for (i = 1; i < (n*n); j++)
	  	{
          	if (Nod(n*n, i) == 1)
				{
					n2_group[j] = i;
					j = j + 1;
				}
      		}

	  //порядок группы квадратов равен n*m(см notes of correctness)
	  //зададим эту группу, то есть будем возводить в квадрат по модулю каждый элемент Z_n^2
      square = (unsigned long int*) calloc(n * m, sizeof(unsigned long int));
      for (i = 1; i <= (n * m); i++)
      {
		buf = (n2_group[i] * n2_group[i])%(n*n);
		for(j = 1; j < i; j++)// цикл проверки не было ли этого числа ранее по индексу
		{
        	if (buf == square[j])
			{
				break;
			}
			else
			{
				square[i] = buf;
			}

		}
      }

 	  //получили группу квадратов, теперь ищем в ней генератор
	  for (i = 1; i <= (n * m); i++)	
 	  {
		if(intpower(square[i], n*m) == 1) c = square[i]; 
	  }
      
	  free (square);
      fclose (params);
      return c;
} 
