/*1715번 카드 정렬하기(C++11)*/
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

std::priority_queue<int, std::vector<int>, std::greater<int> > Mheap;

int N, res;
bool _FLAG;

int main()
{
	int tmp, i, f, s;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &tmp);
		Mheap.push(tmp);
	}
	while(!Mheap.empty())
	{
		if(!_FLAG)
		{
			f = Mheap.top();
			Mheap.pop();
			_FLAG = true;
		}
		else
		{
			s = Mheap.top();
			Mheap.pop();
			_FLAG = false;
			s += f;
			res += s;
			Mheap.push(s);
		}
	}
	printf("%d\n", res);
	return 0;
}
