#include <stdio.h>

static int sum;

void Disc_Num(int N){
	int i, H, T, U;
	H = N / 100;
	T = (N % 100) / 10;
	U = (N % 10);

	if((H-T)==(T-U))
		sum++;
	return;
}

int main(){
	int N, i;
	scanf("%d", &N);

	if(N >= 100){
		sum = 99;
		for(i = 111 ; i <= N ; i++){
			Disc_Num(i);
		}
	}
	else
		sum = N;
	printf("%d\n", sum);
	
	return 0;
}
