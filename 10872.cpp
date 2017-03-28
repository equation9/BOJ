/*10872번 팩토리얼(C++11)*/
#include <cstdio>
int main()
{
	unsigned long long int N, i, res=1;
	scanf("%llu", &N);
	for(i = 1 ; i <= N ; i++)
		res *= i;
	printf("%llu\n", res);
	return 0;
}
