/*10768번 특별한 날(C++11)*/
#include <cstdio>
#define N 218
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	a *= 100;
	a += b;
	if(a < N) printf("Before\n");
	else if(a == N) printf("Special\n");
	else printf("After\n");
}
