/*14517번 팰린드롬 갯수 구하기 (Large)(C++11)*/
#include <cstdio>
#include <cstring>

char str[1001];
int cnt, len, dp[1001][1001];

int Count(int s, int e)
{
	int a, c;
	if(e < s) return 0;
	if(dp[s][e] != -1) return dp[s][e];
	if(s==e) return dp[s][e] = 1;
	
	c = Count(s, e-1)+Count(s+1, e);
	if(str[s] == str[e]) a = 1;
	else a = -Count(s+1, e-1);
	
	return dp[s][e] = (c + a+10007)%10007;
}

int main()
{
	int i, j;
	scanf("%s", str);
	len = strlen(str);
	for(i = 0 ; i < len ; i++)
		for(j = 0 ; j < len ; j++)
			dp[i][j] = -1;
	printf("%d\n", Count(0, len-1));
	return 0;
}
