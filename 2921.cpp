/*2921번 도미노(C++11)*/
#include <cstdio>
int main()
{
	int N, i, j, res=0;
	scanf("%d", &N);
	for(i = 1 ; i <= N ; i++)
	{
		for(j = 0 ; j <= i ; j++)
			res += i+j;
	}
	printf("%d\n", res);
	return 0;
}
