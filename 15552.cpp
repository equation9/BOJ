/*15552번 빠른 A+B*/
#include <cstdio>
int main()
{
	int loop, T;
	int a, b;
	scanf("%d", &T);
	for(loop = 0; loop < T; loop++){
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}
