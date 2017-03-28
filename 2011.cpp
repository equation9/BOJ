/*2011번 암호코드(C++11)*/
#include <cstdio>
#include <cstring>
#define _MOD 1000000
char Pass[5001];
int len, DP[5001];

int main()
{
	int i=0, tmp1, tmp2;
	scanf("%s", Pass);
	len = strlen(Pass);
	DP[0] = 1;
	for(i = 1 ; i <= len ; i++)
	{
		tmp1 = Pass[i-1] -'0';
		if(tmp1 >= 1 && tmp1 <= 9)
			DP[i] = (DP[i] + DP[i-1]) % _MOD;
		if(i==1)
			continue;
		if(Pass[i-2] == '0')
			continue;
		tmp2 = (Pass[i-2]-'0')*10 + Pass[i-1]-'0';
		if(tmp2 >= 10 && tmp2 <= 26)
			DP[i] = (DP[i] + DP[i-2]) % _MOD;
	}
	printf("%d\n", DP[len]);
	return 0;
}
