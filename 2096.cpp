/*2096번 내려가기(C++11)*/
#include <cstdio>
#include <algorithm>

int N, PrevMax[3], PrevMin[3],NowMax[3], NowMin[3];

int main()
{
	int i, j, num;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{
			scanf("%d", &NowMax[j]);
			NowMin[j] = NowMax[j];
			NowMax[j] += std::max(PrevMax[1], (j==1)?std::max(PrevMax[0], PrevMax[2]) : PrevMax[j]);
			NowMin[j] += std::min(PrevMin[1], (j==1)?std::min(PrevMin[0], PrevMin[2]) : PrevMin[j]);
		}
		for(j = 0 ; j < 3 ; j++)
		{
			PrevMax[j] = NowMax[j];
			PrevMin[j] = NowMin[j];
		}
	}
	std::sort(PrevMax, PrevMax+3);
	std::sort(PrevMin, PrevMin+3);
	printf("%d %d\n", PrevMax[2], PrevMin[0]);
	return 0;
}
