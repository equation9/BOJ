/*3055번 탈출(c++11)*/
#include <cstdio>
#include <queue>
#include <utility>


const int Ydir[4] = {1, 0, -1, 0}, Xdir[4] = {0, 1, 0, -1};
int R, C, sy, sx;
char map[51][51];
int Dist[51][51];
std::queue<std::pair<std::pair<int, int>, int> > Q; //({y, x},0:flood 1:sonic}

int main()
{
	int i, j;
	scanf("%d %d", &R, &C);
	for(i = 0 ; i < R ; i++){
		scanf("%s", map[i]);
		for(j = 0 ; j < C ; j++){
			if(map[i][j] == 'S'){
				sy = i;
				sx= j;
			}
			else if(map[i][j] == '*'){
				Dist[i][j] = 1;
				Q.push( { {i, j}, 0 } );
			}
		}
	}
	
	Q.push( {{sy, sx}, 1} );
	Dist[sy][sx] = 1;
	while(!Q.empty())
	{
		int ny = Q.front().first.first;
		int nx = Q.front().first.second;
		int nchk = Q.front().second;
		for(i = 0 ; i < 4; i++){
			int my = ny + Ydir[i];
			int mx = nx + Xdir[i];

			if(my < 0 || mx < 0 || my == R || mx == C || Dist[my][mx] || map[my][mx] == 'X')
				continue;
			if(map[my][mx] == 'D'){
				if(!nchk) continue;

				printf("%d\n", Dist[ny][nx]);
				return 0;
			}
			Dist[my][mx] = Dist[ny][nx] +1;
			Q.push( {{my, mx}, nchk} );
		}
		Q.pop();
	}
	printf("KAKTUS\n");
	
	return 0;
}
