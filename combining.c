#include <stdlib.h>
#include <math.h>
#include <time>
//int mod_func, возможно понадобится, см комментарий ниже
int L_func (int u, int n); //
void combining (int p_, int q_); //

//в этой функции делю u-1 на n на цело(см криптосистема Пэйе)
int L_func(int u, int n){
   
    int c = 0;
    c = (u-1)/n  
    return c
}



//должен прочитать из файла t+1 ключей s_i=SK[i], у которых proof = 1, а так же их c_i=c[i](см share decryption algorithm ) 
//если их меньше, выдать ошибку
// без понятия как это делать, поэтому пока просто обозначил их за SK[i]
// S набор t+1 SK[i]
// t+1 необходимое количество серверов с правильным proof, мы сами задаем этот параметр 
void combining(int p_, int q_, int delta, int tetta, int t)
{
 
    int n = 0;
    int p = 0, q = 0;
	int i = 1, j = 1;
    int MULT = 1;
	p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;
	int M;
	// определяю массив mu_0
	
	unsigned *mu_0;
	mu_0 = (unsigned*)malloc((t+1) * sizeof(unsigned));
	for (i = 1; i<=(t+1); i++)
    {
		mu_0[i] = 1;
// цикл для всех j!=i
		while (j <= (t+1) )
		if(j != i){
        	mu_0[i] = m_0[i] * j/(j - i);
			j = j+1;
		}else{
			j = j+1;
		}
    }
	//вычисляю произведение П c_j ^(2*mu_0[j]) mod n^2(см формулу в combining algorithm 5.1)
	//результат произведения записываю в  MULT
	for (j = 1; j <= (t+1); j++)
	{
		MULT = (MULT*pow(c[j], 2*mu_0[j])) % (pow(n, 2))
	}
	// теперь наконец вычисляю открытый техт M	
	// правда здесь может получится нецелое число, тогда придется переписывать функцию mod_func, которая выдает остаток от деления
	// по идее она должна прибавлять к числителю дроби n, пока частное не станет целым, но я хз как это делать в си
	M = (L_func(MULT) *(1/(4*pow(delta, 2)*tetta))) mod n
	//расшифровано, открытый текст получен
	free mu_0;    
}

int main ()
{
    return 0;
}
