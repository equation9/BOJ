/*4101번 크냐?(C++11)*/
#include <cstdio>
int main()
{
	int a, b;
	while(1)
	{
		scanf("%d%d", &a, &b);
		if(!a && !b)
			return 0;
		if(a > b)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
