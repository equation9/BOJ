/*2178번 미로 탐색(C++11)*/
#include <cstdio>
#include <utility>
#include <queue>
using std::queue;
typedef std::pair<int, int> Pair;

int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1}; //direction

int N, M, visited[100][101];
char Map[100][101];
queue<Pair> Q;

 int main()
{
	int i, y, x, ny, nx;
	scanf("%d %d",&N, &M);
	for(i = 0 ; i < N ; i++) scanf("%s", Map[i]);
	
	Q.push( {0, 0} );
	visited[0][0] = 1;
	while(!Q.empty())
	{
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();
		for(i = 0 ; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if(!visited[ny][nx] && Map[ny][nx] == '1')
			{
				Q.push( {ny, nx} );
				visited[ny][nx] = visited[y][x]+1;
				//printf("Go (%d, %d) value : %d\n", ny, nx, visited[ny][nx]);
			}
		}
	}
	printf("%d\n", visited[N-1][M-1]);
	return 0;
}
