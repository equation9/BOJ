/*2447번 별찍기 - 10(C)*/
#include <stdio.h>
#include <stdlib.h>

char ** Square; //배열을 출력

void Make_blank(int x, int y, int N){
	int i, j;
	for(i = 0 ; i < N ; i++){
		for(j = 0 ; j < N ; j++)
			Square[x+i][y+j] = ' ';
	}
}

void Make_Window(int x, int y, int N){
	if(N < 1)
		return;

	int m = N/3;
	Make_Window(x, y, m);
	Make_Window(x, y+m, m);
	Make_Window(x, y+2*m, m);
	
	Make_Window(x+m, y, m);
	Make_blank(x+m, y+m, m);
	Make_Window(x+m, y+2*m, m);
	
	Make_Window(x+2*m, y, m);
	Make_Window(x+2*m, y+m, m);
	Make_Window(x+2*m, y+2*m, m);
}

int main(){
	int N, i, j;
	scanf("%d", &N);
	//동적 할당으로 크기 지정
	Square = (char **)malloc(N*sizeof(char*));
	for(i = 0 ; i < N ; i++)
		Square[i] = (char *)malloc(2*N*sizeof(char)+1);
	
	for(i = 0 ; i < N ; i++){
		for(j = 0 ; j < N ; j++)
			Square[i][j] = '*';
		Square[i][j] = '\0';
	}

	Make_Window(0, 0, N);

	//free
	for(i = 0 ; i < N ; i++){
		printf("%s\n", Square[i]);
		free(Square[i]);
	}
	free(Square);
	return 0;
}
