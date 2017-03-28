/*1413번 박스 안의 열쇠(C++11)*/
#include <cstdio>
#include <cstring>

long int N, M, A, B, cnt[21][21];

long int gcd(long int a, long int b)
{
	return b ? gcd(b, a%b) : a;
}

long int factorial(long int n)
{
	long int i, res=1;
	for(i = 2 ; i <= n ; i++) res *= i;
	return res;
}

long int dp(long int box, long int bomb)
{
	if(!box) return 1;
	if(!bomb) return 0;
	if(cnt[box][bomb] != -1) return cnt[box][bomb];
	return dp(box-1, bomb-1) + (box-1)*dp(box-1, bomb);
}

int main()
{
	long int i;
	scanf("%ld %ld", &N, &M);
	memset(cnt, -1, sizeof(cnt));
	B = factorial(N);
	A = dp(N, M);
	M = gcd(A, B);
	printf("%ld/%ld\n", A/M, B/M);
	return 0;
}
