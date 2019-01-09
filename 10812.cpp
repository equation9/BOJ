/*10812번 바구니 순서 바꾸기(C++)*/
#include <cstdio>
int N, M;
int A[101];
int R[101];

int main()
{
	int i, j, a,b,c,l;
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N; i++)
		R[i] = i;
	for(l = 0; l < M; l++)
	{
		scanf("%d %d %d", &a, &b, &c);
		for(i = a; i <= b; i++){
			A[i] = R[i];
		}
		j = c;
		for(i = a; i<= b; i++)
		{
			R[i] = A[j];
			j++;
			if(j > b) j = a;
		}
		/*
		for(i = 1; i <= N; i++)
			printf("%d ", R[i]);
		printf("\n");*/
	}
	for(i = 1; i <= N; i++)
		printf("%d ", R[i]);
	printf("\n");
	return 0;
}
