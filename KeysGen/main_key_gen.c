void main_key_gen(unsigned long int p_, unsigned long int q_, int t, int l)
{
      unsigned long int n = (2 * p_ + 1) * (2 * q_ + 1);
 	  unsigned long int m = p_*q_;

      unsigned long int* square;
	  unsigned long int* n2_group;//Z_n^2
      unsigned long int i, j = 0;
      unsigned long int c = 0;
	  unsigned long int buf;
      int a = 1, k = 0;

	  //заполняем массив элементов группы Z_n^2
	  //printf ("n2_group:\n\n");
	  n2_group = (unsigned long int*) calloc(phi(n*n), sizeof(unsigned long int));
      for (i = 1; i < (n*n); i++)
	  	{
          	if (Nod(n*n, i) == 1)
				{
					n2_group[j] = i;
					//printf ("%lu\n", n2_group[j]);
					j = j + 1;
				}
      		}

	  //порядок группы квадратов равен n*m(см notes of correctness)
	  //зададим эту группу, то есть будем возводить в квадрат по модулю каждый элемент Z_n^2
	  unsigned long int ii = 0;
	  //printf ("\n\n\n\n\n\n--------------------------------------------------------------------\nSquare group:\n");
      square = (unsigned long int*) calloc(n * m, sizeof(unsigned long int));
      for (i = 0; (i < (phi(n * n))); i++)
      {
		buf = (n2_group[i] * n2_group[i])%(n*n);




		for(j = 0; j <= ii; j++)// цикл проверки не было ли этого числа ранее по индексу
		{
        	if (buf == square[j])
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
            square[ii] = buf;
            //printf ("%lu\n", square[ii]);
            ii++;
        }

      }

 	  //получили группу квадратов, теперь ищем в ней генератор
 	  //printf ("n * n = %lu;\n", n*n);
 	  //printf ("phi(n * n) = %lu;\n", phi(n*n));
 	  //printf ("n * m = %lu;\n", n*m);
 	  //printf ("phi(n * m) = %lu;\n", phi(n*m));
 	  unsigned long int counter_for_result = 0;
 	  unsigned long int* result_arr = NULL;
      result_arr = (unsigned long int*) calloc (phi(n*m), sizeof(unsigned long int));
 	  unsigned long int counter = 0;
 	  k = 0;
	  for (i = 0; i < (n * m); i++)
 	  {


        for (j = 1; j <= (n * m); j++)
        {
            buf = intpower(square[i], j, n);
            if ((((buf % (n * n)) == 1) && (j != (n*m))))
            {
                k = 0;
                //printf ("Numer %lu is bad, because intpower(%lu, %lu, n) %% (n * n) = %lu == 1\n", square[i], square[i], j, (buf % (n * n)));
                break;
            }
            else
            {
                k = 1;
            }
        }

        if (k == 1)
        {
            result_arr [counter_for_result] = square[i];
            counter_for_result++;

            counter ++;
        }

	  }
	  //printf ("Number of generators = %lu\n", counter);
      srand(time(NULL));
	  unsigned long int result_for_result = 0;
	  result_for_result = rand()%(phi(n*m));

	  if (result_arr[result_for_result] == 0)
      {
          printf ("\nERROR. Main verification key was not generated. File main_key_gen.c\n\n");
          return;
      }
      else
      {
         printf ("\nSTATUS: OK. Main verification key was generated. Result = %lu. File main_key_gen.c\n\n", result_arr[result_for_result]);
      }

	  free (square);
	  free (n2_group);


      FILE* params = NULL;
      params = fopen ("PARAMS.txt", "w");
      if (params == NULL)
      {
          printf ("ERROR. File 'PARAMS.txt' was not found. File main_key_gen.c\n\n");
          return;
      }

      fprintf (params, "%lu %lu %lu", p_, q_, result_arr[result_for_result]);
      fclose (params);

      free(result_arr);
      return;
}
