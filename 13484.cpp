/*13484번 Tarifa(C++11)*/
#include <cstdio>

int X, N, sum;

int main()
{
	int i;
	scanf("%d %d", &X, &N);
	sum = X;
	for(i = 0; i < N; i++){
		int a;
		scanf("%d", &a);
		sum -= a;
		sum += X;
	}
	printf("%d\n", sum);
	return 0;
}
