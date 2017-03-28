/*2443번 별찍기 - 6(C)*/
#include <stdio.h>
int main(){
	int N, i, j;
	scanf("%d", &N);
	for(i = N-1 ; i >= 0 ; i--){
		for(j = i ; j < N-1 ; j++)
			printf(" ");
		for(j = 0 ; j < 2*i+1 ; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
