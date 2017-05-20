/*14545번 Square(C++11)*/
#include<cstdio>
int main()
{
	long long int T, n;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &n);
		printf("%lld\n", n*(n+1)*(2*n+1)/6);
	}
	return 0;
}
