/*10275번 골드 러시(C++11)*/
#include <cstdio>

int main()
{
	int n, T, i;
	long long int a, b, L;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %lld %lld", &n, &a, &b);
		i = 0;
		L = 1;
		while(!(L&b))
		{
			i++;
			L <<= 1;
		}
		printf("%d\n", n-i);
	}
	return 0;
}
