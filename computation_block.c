#include <stdlib.h>
#include <math.h>
#include <time>
void computation_block (int p_, int q_);

void computation_block(int p_, int q_){
	// читает из файла N зашифрованных сообщений от пользователей c[i]
	int n = 0;
    int p = 0, q = 0, i;
	p = 2 * p_ + 1;
    q = 2 * q_ + 1;
    n = p * q;
	int c; 
	for (i = 1; i < N; i++){
		c = (c[i] + c[i]) % pow(n, 2);
	}
	//c и есть ответ к лотерее, надо записать его в файл
}
