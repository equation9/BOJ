/*2069번 보이는 산맥(C++11)*/
#include <cstdio>
#include <utility>
#include <algorithm>

std::pair<long int, long int> P[100001];

int main()
{
	long int N, i, res = 0, r, ps=1;
	scanf("%ld", &N);
	for(i = 0 ; i < N ; i++)
		scanf("%ld %ld", &P[i].first, &P[i].second);
	std::sort(P, P+N);
	for(i = 0 ; i < N ; i++)
	{
		//printf("(%ld, %ld)\n", P[i].first, P[i].second);//디버그
		if(P[i].second <= ps)
			continue;
		r = P[i].second - P[i].first;
		r = r*r;
		res += r;
		if(P[i].first >= ps)
		{
			ps = P[i].second;
			continue;
		}
		r = ps - P[i].first;
		r = r*r;
		res -= r;
		ps = P[i].second;
	}
	printf("%ld\n", res);
	return 0;
}
