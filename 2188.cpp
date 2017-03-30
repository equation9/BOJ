/*2188번 축사 배정(C++11)*/
/*이분 그래프 최대매칭 연습*/
#include <cstdio>
#include <vector>
#include <cstring>
using std::vector;

bool visit[201];
int N, M, MatchA[201], MatchB[201];
vector<int> V[201];

bool Dig(int n)
{
	visit[n] = true;
	for(vector<int>::iterator it = V[n].begin() ; it != V[n].end() ; it++)
	{
		//printf("<%d--%d>\n", n, *it);//디버깅
		if(!MatchB[*it] || (!visit[MatchB[*it]] && Dig(MatchB[*it])))
		{
			MatchA[n] = *it;
			MatchB[*it] = n;
			//printf("%d->%d\n", n, *it); //디버깅
			return true;
		}
	}
	return false;
}

int main()
{
	int i, j, a, b, cnt=0;
	scanf("%d %d", &N, &M);
	for(i = 1 ; i <= N ; i++)
	{
		scanf("%d", &a);
		for(j = 0 ; j < a ; j++)
		{
			scanf("%d", &b);
			V[i].push_back(b);
			//printf("<%d--%d>\n", i, b);//디버깅
		}
	}
	for(i = 1 ; i <= N ; i++)
	{
		if(!MatchA[i])
		{
			memset(visit, false, sizeof(visit));
			if(Dig(i)) cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
