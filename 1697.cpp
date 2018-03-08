/*1697번 숨바꼭질(C++11)*/
/*bfs*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

int Loc[100001];
bool visited[100001];
std::queue<std::pair<int, int> > Q; //위치, 깊이

int main()
{
	int N, K;

	scanf("%d %d", &N, &K);
	if(N >= K)
	{
		printf("%d\n", N-K);
		return 0;
	}
	int now, dig;
	Q.push( {N, 0} );
	while(!Q.empty())
	{
		now = Q.front().first;
		dig = Q.front().second;
		visited[now]= true;
		Q.pop();

		if(now == K)
		{
			printf("%d\n", dig);
			return 0;
		}


		if(now*2 <= 100000 && !visited[now*2]) Q.push( {now*2, dig+1} );
		if(now >= 1 && !visited[now-1]) Q.push( {now-1, dig+1} );
		if(now < 100000 && !visited[now+1]) Q.push( {now+1, dig+1} );
	}

	return 0;
}
