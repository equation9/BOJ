/*11650번 좌표 정렬하기(C++11)*/
/*STL pair*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

int main()
{
	std::vector<std::pair<int, int> > dott;
	int N, i;
	scanf("%d", &N);
	dott.resize(N);
	for(i = 0 ; i < N ; i++)
		scanf("%d %d", &dott[i].first, &dott[i].second);
	std::sort(dott.begin(), dott.end());
	for(i = 0 ; i < N ; i++)
		printf("%d %d\n", dott[i].first, dott[i].second);
	return 0;
}
