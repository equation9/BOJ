/*14505번 팰린드롬 갯수 구하기 (Small)(C++11)*/
#include <cstdio>
#include <cstring>

char str[1001];
int len, dp[1001][1001];

int Count(int s, int e)
{
	//printf("%c", str[s]);//디버그
	if(dp[s][e]) return dp[s][e];
	if(s == e)
	{
		dp[s][e] = 1;
		return dp[s][e];
	}

	int i, j;
	int ccnt=1;
	for(i = s+1; i < e ; i++)
	{
		for(j = e-1 ; j >= i ; j--)
		{
			if(str[i] == str[j])
			{
				ccnt += Count(i, j);
				//printf("%c)", str[e]);//디버그
			}
		}
	}
	return dp[s][e] = ccnt;
}

int main()
{
	int i, j, cnt=0;
	scanf("%s", str);
	len = strlen(str);
	for(i = 0 ; i < len ; i++)
	{
		for(j = len-1 ; j >= i ; j--)
		{
			if(str[i] == str[j])
			{
				cnt += Count(i, j);
			//	printf("\n");//디버그
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
