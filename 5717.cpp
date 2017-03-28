/*5717번 상근이의 친구들(C++11)*/
#include <cstdio>
int main()
{
	int a, b;
	while(1)
	{
		scanf("%d %d", &a, &b);
		if(!a && !b)
			return 0;
		printf("%d\n", a+b);
	}
	return 0;
}
