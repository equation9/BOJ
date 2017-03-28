/*11726번 2xn 타일링(C++11)*/
#include <cstdio>

int cnt[1001];

int Tiling(int n)
{
	if(!cnt[n])
		cnt[n] = (Tiling(n-1) + Tiling(n-2))%10007;
	return cnt[n];
}

int main()
{
	int N;
	cnt[1] = 1;
	cnt[2] = 2;
	scanf("%d", &N);
	printf("%d\n", Tiling(N));
	return 0;
}
