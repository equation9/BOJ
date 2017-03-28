/*5543번 상근날드(C++11)*/
#include <cstdio>
int main()
{
	int N=3, M=2, tmp, burger=3000, drink=3000;
	while(N--)
	{
		scanf("%d", &tmp);
		if(burger > tmp)
			burger = tmp;
	}
	while(M--)
	{
		scanf("%d", &tmp);
		if(drink > tmp)
			drink = tmp;
	}
	printf("%d\n", burger+drink-50);
	return 0;
}
