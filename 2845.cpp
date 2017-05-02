/*2845번 파티가 끝나고 난 뒤(C++11)*/
#include <cstdio>
int main()
{
	int a, b, i;
	scanf("%d %d", &a, &b);
	a *= b;
	for(i = 0; i < 5 ; i++)
	{
		scanf("%d", &b);
		printf("%d ", b-a);
	}
	printf("\n");
}
