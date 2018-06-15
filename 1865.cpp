/*1865번 웜홀(C++11)*/
#include <cstdio>
#include <vector>
#include <utility>

#define INF 987654321

typedef std::pair<int, int> Pair;

int T;
int N, M, W;
std::vector<std::vector<Pair > > adj;
int dist[501];

int main()
{
	int i, j;
	int s, e, t;
	bool flag;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &N, &M, &W);
		//==================
		adj.clear();
		adj.resize(N+1);
		flag = false;
		//===================
		for(i = 0; i < M; i++){
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back( {e, t} );
			adj[e].push_back( {s, t} );
		}
		for(i = 0; i < W; i++){
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back( {e, -t} );
		}
		for(i = 2; i <= N; i++)
			dist[i] = INF;

		for(i = 1; i <= N; i++){
			for(j = 1; j <= N; j++){
				for(Pair k : adj[j]){
					int next = k.first;
					int ndist = k.second;
					if(dist[j] != INF && (dist[next] > dist[j]+ndist)){
						dist[next] = dist[j]+ndist;
						if(i == N) 
							flag = true;
					}
				}
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
