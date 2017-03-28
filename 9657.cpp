/*9657번 돌 게임(C++11)*/
#include <cstdio>
#include <cstring>

int Win[1001], N;

int dp(int n)
{
	if(Win[n] != -1)
		return Win[n];
	int cnt=0;
	if(!dp(n-4)) cnt++;
	if(!dp(n-3)) cnt++;
	if(!dp(n-1)) cnt++;
	
	return Win[n] = cnt ? 1 : 0;
}

int main()
{
	int N;
	scanf("%d", &N);
	memset(Win, -1 , sizeof(Win));
	Win[1] = Win[3] = Win[4] = 1;
	Win[2] = 0;
	printf("%s\n", dp(N) ? "SK" : "CY");
	return 0;
}
