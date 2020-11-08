//factorial
int fact(int *l)
{
    int i;
    for (i = 1; i < *l, i++)
    {
        i = i*(i+1)
    }        
    return i
}
int v(int n)
{
    int *square;
    int i, c;
    int a,k = 1;
    square = (int*)malloc(n * sizeof(int));
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
}
// взять секретные ключи из файла
// написать функцию , которая находить v
// записать в файл
// l number of servers
// v -square of generator in Z_n^2
void vkey_gen(int *p_, int *q_, int *l){
    srand(time(NULL));
    int i;
    //define parameters
    int n, p, q, m, v, delta;//parameters to private keys
    p = 2*p_ + 1;
    q = 2*q_ + 1;
    n = p * q;
    delta = fact(l);
    //define verification key
    int *VK;
    VK = (int*)malloc(l * sizeof(int));
    for (i = 1; i<l; i++)
    {
        VK[i] = pow(v,delta*SK[i]);
    }
   free VK;
   
    
}
