/*2428번 표절(C++11)*/
#include <cstdio>
#include <algorithm>
#include <functional>

int main()
{
	long int N, i, sum=0;
	double s[100001];

	scanf("%ld", &N);
	for(i = 1 ; i <= N ; i++) scanf("%lf", &s[i]);
	std::sort(s+1, s+N+1, std::greater<int>());
	for(i = N-1 ; i >= 1 ; i--)
	{
		while((N > i) && (s[N] < (0.9*s[i]))) N--;
		//printf("<%d> %lf, N:%d\n", i, s[i], N);
		sum += N-i;
	}
	printf("%ld\n", sum);
	return 0;
}
