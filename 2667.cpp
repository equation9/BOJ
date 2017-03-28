/*2667번 단지번호붙이기(C++11)*/
/*dfs*/
#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> Vec;
std::vector<int>::iterator it;
int N;
char map[25][26];
bool visit[25][25];

int bfs(int y, int x)
{
	int cnt=1;
	visit[y][x] = true;
	//printf("(%d,%d)\n", y, x);
	if(y > 0 && map[y-1][x] == '1' && !visit[y-1][x])
	{
		cnt += bfs(y-1, x);
	}
	if(x > 0 && map[y][x-1] == '1' && !visit[y][x-1])
	{
		cnt += bfs(y, x-1);
	}
	if(x < N-1 && map[y][x+1] == '1' && !visit[y][x+1])
	{
		cnt += bfs(y, x+1);
	}
	if(y < N-1 && map[y+1][x] == '1' && !visit[y+1][x])
	{
		cnt += bfs(y+1, x);
	}
	return cnt;
}

int main()
{
	int i, j, a, b;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%s", map[i]);
	}
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < N ; j++)
		{
			if(map[i][j] == '1' && !visit[i][j])
			{
				Vec.push_back(bfs(i, j));
			}
		}
	}
	std::sort(Vec.begin(), Vec.end());
	printf("%lu\n", Vec.size());
	for(it = Vec.begin(); it != Vec.end() ; it++)
	{
		printf("%d\n", *it);
	}
	return 0;
}
