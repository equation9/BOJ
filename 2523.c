/*2523번 별찍기 - 13(C)*/
#include <stdio.h>
#include <math.h>
int main(){
	int N, i, j;
	scanf("%d", &N);
	for(i = -N+1 ; abs(i) < N ; i++){
		for(j = 0 ; j < N-abs(i) ; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
