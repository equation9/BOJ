/*1789번 수들의 합(C++11)*/
#include <cstdio>
int main()
{
	long long int S, i, tmp;
	scanf("%lld", &S);
	for(i = 1 ; i < S ; i++)
	{
		if((i*(i+1)/2) > S)
			break;
	}
	printf("%lld\n", i-1);
	return 0;
}
