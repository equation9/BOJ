/*8979번 올림픽(C++11)*/
#include <cstdio>
#include <cstring>
#include <algorithm>

struct score
{
	int gold, silver, bronze, num;
	bool operator <(const score &B)
	{
		if(this->gold == B.gold)
		{
			if(this->silver == B.silver)
			{
				return this->bronze > B.bronze;
			}
			return this->silver > B.silver;
		}
		return this->gold > B.gold;
	}
	bool operator ==(const score &B)
	{
		return (this->gold == B.gold) && (this->silver == B.silver) && (this->bronze == B.bronze);
	}
};

int N, K;

int main()
{
	int res, i;
	scanf("%d %d", &N, &K);
	score Nation[N];
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d %d %d %d", &Nation[i].num, &Nation[i].gold, &Nation[i].silver, &Nation[i].bronze);
	}
	std::sort(Nation, Nation+N);
	for(i = 0 ; i < N ; i++)
	{
		if(Nation[i].num == K)
		{
			while(i > 0 && (Nation[i] == Nation[i-1]))
			{
				i--;
			}
			printf("%d\n", i+1);
			return 0;
		}
	}
	return 0;
}
