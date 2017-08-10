/*1563번 개근상(C++11)*/
#include <cstdio>
#include <cstring>
#define _MOD 1000000

int Day[1001][3][2], N; //결석 0,1,2연속 지각 0, 1번

int dp(int d, int a, int l)
{
	if(d == N) return 1;
	if(Day[d][a][l] != -1) return Day[d][a][l];
	
	int res=0;
	if(a < 2) res += dp(d+1, a+1, l);
	res %= _MOD;
	
	if(l == 0) res += dp(d+1, 0, l+1);
	res %= _MOD;

	res += dp(d+1, 0, l);
	res %= _MOD;
	
	return Day[d][a][l] = res;
}

int main()
{
	scanf("%d", &N);
	memset(Day, -1 , sizeof(Day));

	printf("%d\n", dp(0,0,0));
	return 0;
}
