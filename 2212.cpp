/*2212번 센서(C++11)*/
#include <cstdio>
#include <algorithm>
#include <functional>

int Express[10000];
int Dist[10000];

int main()
{
	int N, K, i, res, idx=0;
	scanf("%d %d", &K, &N);
	for(i = 0 ; i < K ; i++)
	{
		scanf("%d", &Express[i]);
	}
	std::sort(Express, Express+K);
	/*for(i = 0 ; i < K ; i++)
	{
		printf("%d ", Express[i]);
	}
	printf("\n");*/
	res = Express[K-1] - Express[0];
	
	for(i = 1 ; i < K ; i++)
	{
		Dist[idx++] = Express[i] - Express[i-1]; 
	}
	std::sort(Dist, Dist+K-1, std::greater<int>());
	for(i = 0 ; i < N-1 ; i++)
	{
		//printf("res %d\n", res);
		res -= Dist[i];
	}
	printf("%d\n", res);
	return 0;
}
