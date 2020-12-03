typedef unsigned long long int main_datatype;




main_datatype intpow (main_datatype a, main_datatype b)
{
    main_datatype i = 0, res = a;

    if (b == 0) return 1;

    for (i = 1; i < b; i++)
    {
        res = (res * a);
    }

    return res;
}

main_datatype f_(int i, main_datatype *a, int t)
{

    int k;
    main_datatype c = 0;
    for (k = 0; k < t+1; k++)
    {
        c += a[k] * intpow(i, k);

    }
    return c;
}

main_datatype intpower (main_datatype a, main_datatype b, main_datatype n)
{
    main_datatype i = 0, res = a;

    if (b == 0) return 1;

    for (i = 1; i < b; i++)
    {
        res = (res * a) % (n * n);
    }

    return res;
}

//euclide algorithm
main_datatype Nod(main_datatype a,main_datatype b)
{
    while (a && b)
    {
        if (a >= b)
           a %= b;
        else
           b %= a;
    }

    return (a | b);
}

//function count coprimes
main_datatype coprime(main_datatype a, main_datatype b)
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
main_datatype phi(main_datatype n)
{
    main_datatype result = 0;
    main_datatype k;
    for(k = 1; k <= n; k++)
        result += (coprime(k, n) == 1);

    return result;
}

//factorial
main_datatype fact(int l)
{
    int i;
    main_datatype factorial = 1;
    for (i = 1; i < l; i++)
    {
        factorial = factorial * (i + 1);
    }
    return factorial;
}

//generate random numbers from Z_n^*
main_datatype randZ_n (main_datatype p, main_datatype q)
{

    //srand(time(NULL));
    main_datatype output = 0;
    output = rand () % (p * q);

    while (Nod(output, (p*q)) != 1)
    {
        output = rand () % (p * q);
    }
    return output;
}

main_datatype intdiv (main_datatype a, main_datatype b, main_datatype n) // a / b
{
    main_datatype i = 0;
    while (((a + i * (n * n)) % b) != 0)
    {
        i++;
    }

    return (((a + i * (n * n)) / b) % (n * n));
}

main_datatype intdiv_n (main_datatype a, main_datatype b, main_datatype n) // a / b
{
    main_datatype i = 0;
    while (((a + i * (n)) % b) != 0)
    {
        i++;
    }

    return (((a + i * (n)) / b) % (n));
}

main_datatype intabs (main_datatype a, main_datatype b)
{
    if (a >=b ) return (a - b);
    else        return (b - a);
}
