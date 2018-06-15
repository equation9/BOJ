/*1525번 퍼즐(C++11)*/
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int Puzzle[4][4];
int Ydir[4]= {1, 0, -1, 0}, Xdir[4] = {0, 1, 0, -1};
queue<int> Q;
map<int, int > dist;
int Pos[20];


int bfs(int s)
{
	if(s == 123456780) return 0;

	dist[s] = 1;
	Q.push(s);
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		int zero = 0;
		int tmp = cur;
		int d = dist[cur];
		for(int i = 8 ; i >= 0 ; i--){
			if(tmp%10 == 0){
				zero = i;
				break;
			}
			tmp /= 10;
		}

		int y = zero/3, x = zero%3;
		for(int i = 0 ; i < 4; i++){
			int ny = y + Ydir[i];
			int nx = x + Xdir[i];
			if(ny < 0 || nx < 0 || ny >= 3 || nx >= 3) continue;

			int np = ny*3+nx;
			int od = ((cur/Pos[np])%10) * Pos[zero];
			int nd = ((cur/Pos[np])%10) * Pos[np];
			int next = cur - nd + od;
			if(!dist[next]){
				Q.push(next);
				dist[next] = d+1;
			}
		}
	}
	return dist[123456780] - 1;
}

int main()
{
	int i;
	int start = 0;
	Pos[0] = 1;
	for(i = 1 ; i <= 10 ; i++) Pos[i] = Pos[i-1] * 10;
	for(i = 8 ; i >= 4 ; i--){
		swap(Pos[i], Pos[8-i]);
	}

	for(i = 0 ; i < 9 ; i++){
		int tmp;
		cin >> tmp;
		start *= 10;
		start += tmp;
	}
	cout << bfs(start)<<endl;
	return 0;
}
