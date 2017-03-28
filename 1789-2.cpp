#include <cstdio>
#include <cmath>
int main()
{
	long long int N, K;
	scanf("%lld", &N);
	K = (long long int)sqrtl(2.0 * (long double)N);
	while(N >= K*(K+1)/2) K++;
	printf("%lld\n", K-1);
	return 0;
}
