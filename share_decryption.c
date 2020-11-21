#include <stdlib.h>
#include <math.h>
#include <time.h>

int randZ_n (int p, int q); //generate random numbers from Z_n^*
int has_func();//hash function to check natural log equivalence
void share_decryption (int p_, int q_); //generate Key

//надо написать хэш-функцию hash_func
//c_i = c^(2*DELTA*s_i) (лучше сделать это вычисление  в отдельной функции, потому что его производит игрок со своим s_i)
//так что на вход подается уже c_i
//v_i = VK[i]
//видимо делается на защищенном сервере(есть s)
//r- случайное число в [0, A], пусть A = n
//x, x_ параметры для нахождения e, е параметр проверки идентичности логарифмов
//
//
void share_decryption(int p_, int q_, int s_i, delta, v, VK_i, c_i, c )
{
    srand(time(NULL));

    //define parameters for shared decryption
    int n = 0;
    int p = 0, q = 0;
	int e = 0, r = 0, x = 0, x_=0, y = 0
    int g, G, h, H
	p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;
	r = rand() % n;
	x =	pow(pow(c, 4*delta) % (n*n), r);
	x_= pow(pow(v, delta) % (n*n), r);
	e = hash_func(pow(c, 4*delta), pow(v, delta) % (n*n), pow(c_i, 2), VK_i, x, x_)//определяем параметр e
	g=pow(c, 4*delta) % (n*n)
	h= pow(v, delta) % (n*n) 
	G= pow(c_i, 2)
	H= VK_i
	y = r + e*s_i;
	if (e == hash_func(g, h, G, H, pow(g, y)/pow(G, e), pow(h, y)/pow(H, e)))
	{
		proof = 1//игрок не прошел проверку по секретному ключу
	}else{
		proof = 0//игрок не прошел проверку по секретному ключу
	}
		

	

}

int main ()
{
    return 0;
}
