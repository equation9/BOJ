/*2869번 달팽이는 올라가고 싶다(C++11)*/
#include <cstdio>
int main()
{
	long long int A, B, V, i;
	scanf("%lld %lld %lld", &A, &B, &V);
	i = 0;
	while((A-B)*i+A < V)
	{
		i++;
	}
	printf("%lld\n", i+1);
	return 0;
}
