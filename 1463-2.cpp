/*1463번 1로 만들기(C++)*/
/*DP*/
#include <cstdio>
#include <cstring>
int N, dp[1000001];

void Make_one(int n)
{
	int tmp;
	if(n == 1)
		return;
	if(dp[n] >= 0)
		return;

	//3으로 나눔
	if(!(n%3))
	{	
		if(dp[n/3]<0)
			Make_one(n/3);
		tmp = dp[n/3] + 1;
		if(dp[n]<0 || (dp[n]>=0 && (tmp < dp[n])))
			dp[n] = tmp;
	}
	//2로 나눔
	if(!(n%2))
	{
		if(dp[n/2]<0)
			Make_one(n/2);
		tmp = dp[n/2] + 1;
		if(dp[n]<0 || (dp[n]>=0 && (tmp < dp[n])))
			dp[n] = tmp;
	}
	//1을 뺌
	if(dp[n-1] < 0)
		Make_one(n-1);
	tmp = dp[n-1] + 1;
	if(dp[n] < 0 || (dp[n]>=0 && (tmp < dp[n])))
		dp[n] = tmp;	
	printf("n : %d, %d\n", n , dp[n]);	
	return;
}

int main()
{
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	dp[1] = 0;
	Make_one(N);
	printf("%d\n", dp[N]);
	return 0;
}
