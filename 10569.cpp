/*10569번 다면체(C++11)*/
#include <cstdio>
int main()
{
	int T, v, e;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &v, &e);
		printf("%d\n", e-v+2);
	}
	return 0;
}
