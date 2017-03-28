/*2097번 조약돌(C++11)*/
#include <cstdio>
#include <cmath>

int main()
{
	long double N;
	long long int sn, mn, res;
	scanf("%Lf", &N);
	sn = (long long int)sqrt(N);
	mn = (long long int)N - sn*sn;
	res = sn*4;
	res += (mn/sn)*2;
	if(mn%sn)
		res += 2;
	//printf("mn = %lld sn = %lld\n", mn, sn);//디버깅
	if(N == 1L || N == 2L) res = 8;
	printf("%lld\n", res-4);
	return 0;
}
