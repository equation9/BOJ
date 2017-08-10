/*14674번 STOP USING MONEY(C++11)*/
#include <cstdio>
#include <vector>
#include <algorithm>

struct Game
{
	double CE;
	int price;
	int num;

	bool operator<(const Game b)
	{
		if(this->CE == b.CE)
		{
			if(this->price == b.price)
			{
				return this->num < b.num;
			}
			return this->price < b.price;
		}
		return this->CE > b.CE;
	}
};

int  main()
{
	int N,K, i;
	std::vector<Game> V;
	scanf("%d %d", &N, &K);
	for(i = 0 ; i < N ; i++)
	{
		int n, c, h;
		scanf("%d %d %d", &n, &c, &h);
		V.push_back( { (double)h/(double)c, c, n }) ;
	}
	std::sort(V.begin(), V.end());
	for(i = 0 ; i < K ; i++)
	{
		printf("%d\n", V[i].num);
	}

	return 0;
}
