/*2446번 별찍기 - 9(C)*/
#include <stdio.h>
#include <math.h>
int main(){
	int N, i, j;
	scanf("%d", &N);
	for(i = -N+1 ; abs(i) < N ; i++){
		for(j = N-1 ; j > abs(i) ; j--)
			printf(" ");
		for(j = 0 ; j < 2*abs(i) +1 ; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
