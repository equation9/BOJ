/*2442번 별찍기 - 5(C)*/
#include <stdio.h>
int main(){
	int N, i, j;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		printf("%*c", N-i-1, ' ');
		for(j = 0 ; j < 2*i+1 ; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
