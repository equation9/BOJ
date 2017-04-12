/*2109번 순회강연(C++11)*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
typedef std::pair<int, int> Pair; //(pay, num)

int N, Max=10000;

std::vector<Pair> Date[10001];
std::vector<Pair>::iterator it;

std::priority_queue<Pair> MaxHeap;

int main()
{
	int i, j, tmp;
	Pair now;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		now.second = i;
		scanf("%d %d", &now.first, &tmp);
		Max = std::max(Max, tmp);
		Date[tmp].push_back(now);
	}
	tmp = 0;
	for(i = Max ; i >= 1 ; i--)
	{
		for(it = Date[i].begin() ; it != Date[i].end() ;it++)
		{
			MaxHeap.push(*it);
		}
		if(MaxHeap.empty()) continue;
		now = MaxHeap.top();
		//printf("i %d, +pay %d\n", i, now.first);//디버그
		tmp += now.first;
		MaxHeap.pop();
	}
	printf("%d\n", tmp);
	return 0;
}
