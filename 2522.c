/*2522번 별찍기 - 12(C)*/
#include <stdio.h>
#include <math.h>
int main(){
	int N, i, j;
	scanf("%d", &N);
	for(i = -N+1 ; abs(i) < N ; i++){
		for(j = 0 ; j < abs(i) ; j++)
			printf(" ");
		for(j = 0 ; j < N-abs(i) ; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
