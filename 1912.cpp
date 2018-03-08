/*1912번 연속합(C++11)*/
#include <cstdio>
#include <algorithm>

int num[100001], dp[100001], N;

int cnt(int n)
{
	if(dp[n] != -1) return dp[n];
	dp[n] = std::max(cnt(n-1)+num[n], num[n]);
	return dp[n];
}


int main()
{
	int i, max=-1001;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++) scanf("%d", &num[i]);
	std::fill(dp, dp+N, -1);
	dp[0] = num[0];
	cnt(N-1);
	for(i = 0 ; i < N ; i++) max = std::max(max, dp[i]);
	printf("%d\n", max);
	return 0;
}
