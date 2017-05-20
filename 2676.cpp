/*2672번 라스칼 삼각형(C++11)*/
#include <cstdio>
int main()
{
	int T, N, M;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &M);
		printf("%d\n", M*(N-M)+1);
	}
	return 0;
}
