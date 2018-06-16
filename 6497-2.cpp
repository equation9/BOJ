/*6497번 전력난*/
/*mst*/
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <functional>
typedef std::pair<int, int> Pair;

int M, N, res, cnt;
std::vector<std::vector<Pair > > adj;
std::priority_queue<Pair, std::vector<Pair > , std::greater<Pair > > minHeap;
bool visit[200001];

int main(){
	int i;
	while(1){
		scanf("%d %d", &M, &N);
		if(!M && !N) return 0;
		adj.clear();
		adj.resize(M+1);
		memset(visit, 0, sizeof(visit));
		res = 0;
		cnt = 0;

		for(i = 0 ; i < N; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back( {c, b} );
			adj[b].push_back( {c, a} );
			res += c;
		}
		
		minHeap.push( {0, 0} );
		while(!minHeap.empty())
		{
			int now = minHeap.top().second;
			int ndist = minHeap.top().first;
			minHeap.pop();
			if(visit[now]) continue;
			visit[now] = true;
			cnt += ndist;

			for(Pair next : adj[now]){
				if(visit[next.second]) continue;
				minHeap.push(next);
			}
		}
		printf("%d\n", res- cnt);
	}
	return 0;
}
