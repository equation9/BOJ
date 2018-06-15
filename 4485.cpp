/*4485번 녹색 옷 입은 애가 젤다지?(C++11)*/
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#define INF 87654321
typedef std::pair<int, int> Pair;  //dist, dest(dest/N=y, dest%N=x)

int N;
int map[126][126];
int dist[126][126];

std::priority_queue<Pair, std::vector<Pair > , std::greater<Pair > > minHeap;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
	int T = 0;
	int i, j;
	while(1){
		scanf("%d", &N);
		if(!N) return 0;
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				scanf("%d", &map[i][j]);
				dist[i][j] = INF;
			}
		}
		dist[0][0] = map[0][0];

		minHeap.push( {dist[0][0], 0} );
		while(!minHeap.empty())
		{
			int ndist = minHeap.top().first;
			int y = minHeap.top().second / N;
			int x = minHeap.top().second % N;
			minHeap.pop();
			if(ndist > dist[y][x]) continue;
			for(i = 0; i < 4; i++)
			{
				int ny = y+dy[i];
				int nx = x+dx[i];
				if(ny < 0 || nx < 0 || ny > N-1 || nx > N-1) continue;

				if(ndist + map[ny][nx] < dist[ny][nx]){
					dist[ny][nx] = ndist + map[ny][nx];
					//printf("dist[%d][%d] = %d\n", ny, nx, dist[ny][nx]);//debug
					minHeap.push( {dist[ny][nx], ny*N+ nx} );
				}
			}
		}
		printf("Problem %d: %d\n", ++T, dist[N-1][N-1]);
	}
	return 0;
}
