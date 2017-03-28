/*14430번 자원 캐기(C++11)*/
#include <cstdio>
#include <algorithm>

int map[301][301], dp[301][301], MAX, N, M;

int dig(int y, int x)
{
	if((y < 0) || (x < 0))
		return 0;
	if(dp[y][x] != -1)
		return dp[y][x];
	dp[y][x] = map[y][x] + std::max(dig(y-1, x), dig(y, x-1));
	MAX = std::max(MAX, dp[y][x]);
	return dp[y][x];
}

int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < M ; j++)
		{
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}
	dp[0][0] = map[0][0];
	MAX = dp[0][0];
	dig(N-1, M-1);
	printf("%d\n", MAX);
	return 0;
}
