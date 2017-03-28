/*1834번 나머지와 몫이 같은 수(C++11)*/
#include <cstdio>
int main()
{
	long long int N, sum=0, i;
	scanf("%lld", &N);
	for(i = 1 ; i < N ; i++)
	{
		sum += N*i+i;
	}
	printf("%lld\n", sum);
	return 0;
}
