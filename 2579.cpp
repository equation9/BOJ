/*2579번 계단 오르기(C++11)*/
#include <cstdio>
#include <algorithm>

int cost[302], dp[302][2], N;

int main()
{
	scanf("%d", &N);
	int i;
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &cost[i]);
	}

	dp[0][0] = dp[0][1] = cost[0];
	dp[1][0] = cost[1];
	
	for(i = 0 ; i<N ; i++)
	{
		dp[i+1][1] = std::max(dp[i+1][1], dp[i][0]+cost[i+1]);
		dp[i+2][0] = std::max(dp[i+2][0], std::max(dp[i][0], dp[i][1]) + cost[i+2]);
	}
	printf("%d\n", std::max(dp[N-1][0], dp[N-1][1]));
	return 0;
}
