/*1008번 A/B(C++11)*/
#include <cstdio>
int main()
{
	int a, b;
	int cnt = 0;
	scanf("%d %d", &a, &b);
	printf("%d", a/b);
	a %= b;
	if(!a) {
		printf("\n");
		return 0;
	}

	printf(".");
	while(a && cnt < 10)
	{
		a *= 10;
		printf("%d", a/b);
		a %= b;
		cnt++;
	}
	printf("\n");
	return 0;
}
