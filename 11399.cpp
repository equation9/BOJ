/*11399번 ATM(C++11)*/
#include <cstdio>
#include <algorithm>
int main()
{
	int N, P[1001], i, cnt=0;
	scanf("%d", &N);
	for(i = 0 ;i < N ; i++) scanf("%d", &P[i]);
	std::sort(P, P+N);
	for(i = 0 ; i < N ; i++)
	{
		cnt += P[i]*(N-i);
	}
	printf("%d\n", cnt);
	return 0;
}
