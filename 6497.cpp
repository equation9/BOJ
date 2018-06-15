/*6497번 전력난(C++11)*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>

#define INF 654321
typedef std::pair<int, int> Pair;

int M, N;//집 길
bool visit[200001];
std::vector<Pair> adj[200001];//dist, to
std::priority_queue<Pair , std::vector<Pair> , std::greater<Pair> > mheap;

int main()
{
	int i;
	while(1){
		scanf("%d %d", &M, &N);
		if(!M && !N) return 0;
		
		int res = 0;
		for(i = 0 ; i < N ; i++){
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			adj[a].push_back( {d, b} );
			adj[b].push_back( {d, a} );
			res += d;
		}

		memset(visit, 0, sizeof(visit));
		
		mheap.push( {0, 0} );
		while(!mheap.empty()){
			int ndist  = mheap.top().first;
			int now  = mheap.top().second;
			mheap.pop();
			if(visit[now]) continue;
			visit[now] = true;
			res -= ndist;
		//	printf("select:(%d)-%d\n", ndist, now);//debug

			for(Pair next : adj[now]){
				if(visit[next.second])
					continue;
				mheap.push(next);
			}
		}
		for(i = 0 ; i < M; i++)
			adj[i].clear();
		printf("%d\n", res);
	}
	return 0;
}
