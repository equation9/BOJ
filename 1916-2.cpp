/*1916번 최소비용 구하기(C++11)*/
/*dijkstra*/
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#define INF 10000000001
typedef std::pair<long long int, int> Pair;

int N, M;
int s, e;
long long int dist[1001];
std::vector<Pair > adj[1001];
std::priority_queue<Pair, std::vector<Pair > , std::greater<Pair > > minHeap;

int main()
{
	int i;
	scanf("%d %d", &N, &M);
	for(i = 0; i < M; i++){
		int a, b;
		long long int c;
		scanf("%d %d %lld", &a, &b, &c);
		adj[a].push_back( {c, b} );
	}
	scanf("%d %d", &s, &e);
	
	for(i = 1; i <= N; i++){
		dist[i] = INF;
		//printf("init: %lld\n", dist[i]); //debug
	}
	dist[s] = 0;
	minHeap.push( {0, s} );
	while(!minHeap.empty()){
		int now = minHeap.top().second;
		long long int ndist = minHeap.top().first;
		minHeap.pop();
		if(ndist > dist[now]) continue;
		for(Pair np : adj[now]){
			int next = np.second;
			long long int nd = np.first;
			if(dist[next] == INF || (ndist + nd < dist[next])){
				dist[next] = ndist+nd;
				//printf("dist[%d] = %lld\n", next, dist[next]);//debug
				minHeap.push( {dist[next], next} );
			}
		}
	}
	printf("%lld\n", dist[e]);
	return 0;
}
