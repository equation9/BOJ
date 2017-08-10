/*13565번 침투(C++11)*/
#include <cstdio>

char map[1001][1001];
int N, M;

bool dfs(int y, int x)
{
	bool res = false;
	if(y == N-1) return true;
	map[y][x] = '1';
	if(y > 0 && map[y-1][x] == '0') res = res || dfs(y-1, x);
	if(y < N-1 && map[y+1][x] == '0') res = res || dfs(y+1, x);
	if(x > 0 && map[y][x-1] == '0') res = res || dfs(y, x-1);
	if(x < M-1 && map[y][x+1] == '0') res = res || dfs(y, x+1);
	return res;
}

int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%s", map[i]);
	}
	for(i = 0 ; i < M ; i++)
	{
		if(map[0][i] == '0' && dfs(0, i))
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
