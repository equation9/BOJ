/*2156번 포도주 시식(C++11)*/
/*n개의 포도주일때 최대 시식가능 량*/
#include <cstdio>
#include <algorithm>

int Wine[10010], N, dp[10010];

int go(int n)
{
	if(n < 0) return 0;
	if(dp[n] != -1) return dp[n];
	return dp[n] = std::max(std::max(go(n-1), go(n-2)+Wine[n]), go(n-3)+Wine[n]+Wine[n-1]);
}

int main()
{
	int i;
	scanf("%d", &N);
	for(i = 0; i < N ; i++)
	{
		scanf("%d", &Wine[i]);
	}
	std::fill(dp, dp+N, -1);
	dp[0] = Wine[0];
	dp[1] = Wine[0]+Wine[1];
	printf("%d\n", go(N-1));
	return 0;
}
