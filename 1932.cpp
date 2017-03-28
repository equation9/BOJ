/*1932번 숫자삼각형(C++11)*/
#include <cstdio>
#include <algorithm>
int map[501][501], N, DP[501][501], MAX;

int sum(int y, int x)
{
	if((x > y) || (x < 0) || (y < 0))
		return 0;
	if(DP[y][x] != -1)
		return DP[y][x];
	DP[y][x] = map[y][x] + std::max(sum(y-1, x-1), sum(y-1, x));
	return DP[y][x];
}

int main()
{
	int i, j;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < i+1 ; j++)
		{
			scanf("%d", &map[i][j]);
			DP[i][j] = -1;
		}
	}
	DP[0][0] = map[0][0];
	for(i = 0 ; i < N ; i++)
	{
		MAX = std::max(MAX, sum(N-1, i));
	}
	printf("%d\n", MAX);
	return 0;
}
