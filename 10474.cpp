/*10474번 분수좋아해?(C++11)*/
#include <cstdio>
int main()
{
	long long int A, B;
	while(1)
	{
		scanf("%lld %lld", &A, &B);
		if(!A && !B)
			return 0;
		printf("%lld %lld / %lld\n", A/B, A%B, B);
	}
	return 0;
}
