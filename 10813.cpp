/*10831번 공 바꾸기(C++11)*/
#include <cstdio>

int Bask[102];

int main()
{
	int i, N, M, a, b, tmp;
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N ; i++)
		Bask[i] = i;

	while(M--)
	{
		scanf("%d %d", &a, &b);
		tmp = Bask[a];
		Bask[a] = Bask[b];
		Bask[b] = tmp;
	}
	for(i = 1 ; i <= N ; i++)
		printf("%d ", Bask[i]);
	printf("\n");
	return 0;
}
