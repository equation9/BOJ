/*6543번 The Bottom of a Graph(C++11)*/
/*scc?*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

int N, M;
std::vector<std::vector<int> > adj;
std::vector<std::vector<int> > radj;
std::stack<int> S;
bool visit[5001];
bool bottom[5001];
int scc[5001];
int ssize;

void dfs(int a){
	visit[a] = true;
	for(int b : adj[a]){
		if(visit[b]) continue;
		dfs(b);
	}
	S.push(a);
	return;
}
void rdfs(int a){
	visit[a] = true;;
	scc[a] = ssize;
//	printf("%d :%d\n", ssize, a);//debug
	for(int b : radj[a]){
		if(visit[b]) continue;
		rdfs(b);
	}
	return;
}

int main()
{
	int i;
	while(1)
	{
		scanf("%d", &N);
		if(!N) return 0;
		scanf("%d", &M);
		
		adj.clear();
		adj.resize(N+1);
		radj.clear();
		radj.resize(N+1);
		memset(scc, -1, sizeof(scc));
		memset(bottom, 1, sizeof(bottom));
		ssize = 0;

		for(i = 1; i <= M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			radj[b].push_back(a);
		}

		memset(visit, 0, sizeof(visit));
		for(i = 1; i <= N; i++){
			if(visit[i]) continue;
			dfs(i);
		}
		memset(visit, 0, sizeof(visit));
		while(!S.empty()){
			int now = S.top();
			S.pop();
			if(visit[now]) continue;
			rdfs(now);
			ssize++;
		}
		for(i = 1; i <= N; i++){
			if(!bottom[i]) continue;
			for(int j : adj[i]){
				if(scc[i] != scc[j]){
					for(int k = 1; k <= N; k++){
						if(scc[i] == scc[k])
							bottom[k] = false;
					}
					break;
				}
			}
		}
		for(i = 1; i <= N; i++){
			if(!bottom[i]) continue;
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
