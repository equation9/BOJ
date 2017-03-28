/*2448번 별찍기 - 11(C)*/
#include <stdio.h>
#include <stdlib.h>

char ** Star; //배열을 출력

void Make_blank(int x, int y, int N){
	int i, j, k= 2*N-1;
	for(i = 0 ; i < N ; i++){
		for(j = 0 ; j < k ; j++)
			Star[x+i][y+i+j] = ' ';
		k -= 2;
	}
}

void Make_Pyramid(int x, int y, int N){
	if(N < 3)
		return;

	int m = N/2;
	Make_Pyramid(x, y, m);
	Make_Pyramid(x+m, y-m, m);
	Make_Pyramid(x+m, y+m, m);
	Make_blank(x+m, y-m+1, m);
}

int main(){
	int N, i, j;
	scanf("%d", &N);
	//동적 할당으로 크기 지정
	Star = (char **)malloc(N*sizeof(char*));
	for(i = 0 ; i < N ; i++)
		Star[i] = (char *)malloc(2*N*sizeof(char)+1);
	
	for(i = 0 ; i < N ; i++){
		j = 0;
		for(j ; j < N-i-1 ; j++)
			Star[i][j] = ' ';
		for(j ; j < N+i ; j++)
			Star[i][j] = '*';
		for(j ; j < 2*N-1 ; j++)
			Star[i][j] = ' ';
		Star[i][j] = '\0';
	}

	Make_Pyramid(0, N-1, N);

	//free
	for(i = 0 ; i < N ; i++){
		printf("%s\n", Star[i]);
		free(Star[i]);
	}
	free(Star);
	return 0;
}
