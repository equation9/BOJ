/*1987번 알파벳(C++11)*/
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int R, C;
int y_dir[4] = {1, 0, -1, 0};
int x_dir[4] = { 0, 1, 0, -1 };
char Map[21][21];
bool alphabet[28]; //visit

int dfs(int y, int x, int cnt)
{
	int i;
	int ny, nx;
	int res = cnt;

	alphabet[(int)(Map[y][x] - 'A')] = true;
	for (i = 0; i < 4; i++) {
		ny = y + y_dir[i];
		nx = x + x_dir[i];
		if ((ny < 0) || (nx < 0) || (ny >= R) || (nx >= C)) continue;
		if (alphabet[(int)(Map[ny][nx] - 'A')]) continue;
		res = max(res, dfs(ny,nx, cnt+1));
	}
	alphabet[(int)(Map[y][x] - 'A')] = false;
	return res;
}

int main()
{
	int i;
	cin >> R >> C;
	for (i = 0; i < R; i++)
			cin >> Map[i];
	cout << dfs(0, 0, 1)<<endl;
	return 0;
}
