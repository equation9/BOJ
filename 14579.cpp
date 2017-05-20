/*14579번 덧셈과 곱셈(C++11)*/
#include <cstdio>
int main()
{
	int a, b, i, res=1;
	scanf("%d %d", &a, &b);
	for(i = a ; i <= b ; i++)
	{
		res *= i*(i+1)/2;
		res %= 14579;
	}
	printf("%d\n", res);
	return 0;
}
