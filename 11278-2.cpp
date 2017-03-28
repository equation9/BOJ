/*STL 활용하기*/
#include <cstdio>
#include <queue>
#include <functional>
#include <vector>

std::priority_queue<int> Mheap;
std::priority_queue<int, std::vector<int> , std::greater<int> > mheap;

int main()
{
	int N, input, obj;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &input);
		if(input)
		{
			Mheap.push(input);
			continue;
		}
		if(Mheap.empty())
			obj = 0;
		else
		{
			obj = Mheap.top();
			Mheap.pop();
		}
		printf("%d\n", obj);
	}
	return 0;
}
