/*7571번 점 모으기(C++11)*/
#include <cstdio>
#include <algorithm>
#include <cmath>

int X[100000], Y[100000], N, M;

int main()
{
	int i, j, XMID, YMID, sum=0;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < M ; i++)
	{
		scanf("%d %d", &X[i], &Y[i]);
	}
	std::sort(X, X+M);
	std::sort(Y, Y+M);
	XMID = X[M/2];
	YMID = Y[M/2];
	for(i = 0 ; i < M ; i++)
	{
		sum += abs(X[i]-XMID)+abs(Y[i]-YMID);
	}
	printf("%d\n", sum);
	return 0;
}
