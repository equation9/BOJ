/*14612번 김식당(C++11)*/
#include <cstdio>
#include <list>
#include <utility>
#include <cstring>
using namespace std;

list<pair<int, int> > L;

int main()
{
	int n, M, ti, ta;
	char order[10];
	scanf("%d %d", &n, &M);
	for(int loop = 0 ; loop < n ; loop++)
	{
		scanf("%s", order);
		if(!strncmp(order, "order", 5))
		{
			scanf("%d %d", &ta, &ti);
			L.push_back( {ti, ta}) ;
		}
		else if(!strncmp(order, "sort", 4))
		{
			L.sort();
		}
		else //complete
		{
			scanf("%d", &ta);
			for(list<pair<int, int>>::iterator it = L.begin(); it != L.end() ; it++)
			{
				if(it->second == ta)
				{
					it = L.erase(it);
					it--;
				}
			}
		}

		if(L.empty()) printf("sleep\n");
		else
		{
			for(pair<int, int> i : L)
			{
				printf("%d ", i.second);
			}
			printf("\n");
		}
	}
	return 0;
}
