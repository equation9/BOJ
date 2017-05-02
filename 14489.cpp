/*치킨 두 마리 (...)(C++11)*/
#include <cstdio>
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", a+b >= 2*c ? a+b-2*c : a+b);
	return 0;
}
