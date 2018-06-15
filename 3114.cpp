/*3114번 사과와 바나나(C++11)*/
#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>

int R, C;
int map[2][1501][1501]; //{ A(가로), B(세로) }
int mem[1501][1501]; //{ A, B }

int dp(int y, int x)
{
	if(mem[y][x] != -1) return mem[y][x];

	int res = dp(y-1, x) + map[0][y][x-1];
	res = std::max(res, dp(y, x-1) + map[1][y-1][x]);
	res = std::max(res, dp(y-1, x-1) + map[0][y][x-1] + map[1][y-1][x]);

	return mem[y][x] = res;
}

int main()
{
	int i, j, tmp;
	char c;
	scanf("%d %d", &R, &C);

	for(i = 0; i < R; i++){
		for(j = 0; j < C; j++){
			mem[i][j] = -1;
			if(i > 0)
				map[1][i][j] = map[1][i-1][j];
			else
				mem[i][j] = 0;
			if(j > 0)
				map[0][i][j] = map[0][i][j-1];
			else
				mem[i][j] = 0;

			getchar();
			c = getchar();
			scanf("%d", &tmp);
			map[c-'A'][i][j] += tmp;
		}
	}
	printf("%d\n", dp(R-1, C-1));
	return 0;
}
