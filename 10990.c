/*10990번 별 찍기 - 15(C)*/
#include <stdio.h>
int main(){
	int N, i, j;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		for(j = N-i ; j > 1 ; j--)
			printf(" ");
		printf("*");
		for(j = 0 ; j < 2*i-1 ; j++)
			printf(" ");
		if(i)
			printf("*");
		printf("\n");
	}
	return 0;
}
