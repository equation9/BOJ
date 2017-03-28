/*2563번 색종이(C++11)*/
#include <cstdio>

int Paper[100][100];

void Coloring_Paper(int x, int y)
{
	int i, j;
	for(i = x ; i < x+10 ; i++)
	{
		for(j = y ; j < y+10 ; j++)
		{
			Paper[i][j] = 1;
		}
	}
}

int main()
{
	int N, x, y, i, j, cnt=0;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d %d", &x, &y);
		Coloring_Paper(x, y);
	}
	for(i = 0 ; i < 100 ; i++)
	{
		for(j = 0 ; j < 100 ; j++)
			cnt += Paper[i][j];
	}
	printf("%d\n", cnt);
	return 0;
}
