/*9461번 파도반 수열(C++11)*/
#include <cstdio>

long long int dp[101];

long long int dig(int n)
{
	if(dp[n])
		return dp[n];
	return dp[n] = dig(n-2) + dig(n-3);
}

int main()
{
	int T, N;
	scanf("%d", &T);
	dp[0] = dp[1] = dp[2] = 1;
	dp[3] = 2;
	while(T--)
	{
		scanf("%d", &N);
		printf("%lld\n", dig(N-1));
	}
	return 0;
}
