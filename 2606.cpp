/*2606번 바이러스(C++11)*/
/*bfs*/
#include <cstdio>
#include <queue>

int N;
bool map[101][101], visit[101];
std::queue<int> Que;

int bfs()
{
	int idx, i, cnt=0;
	visit[1] = true;
	Que.push(1);
	while(!Que.empty())
	{
		idx = Que.front();
		Que.pop();
		for(i = 1 ; i <= N ; i++)
		{
			if(map[idx][i] && !visit[i])
			{
				visit[i] = true;
				Que.push(i);
				cnt++;
				//printf("%d->%d\n", idx, i );
			}
		}
	}
	return cnt;
}

int main()
{
	int i, a, b, M;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < M ; i++)
	{
		scanf("%d %d", &a, &b);
		map[a][b] = true;
		map[b][a] = true;
	}
	printf("%d\n", bfs());
	return 0;
}
