/*4196번 도미노(C++11)*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

int T;
int N, M;

std::vector<std::vector<int> > adj;
std::vector<std::vector<int> > radj;
std::stack<int> S; //stack
bool visit[100001];
int group[100001];

int ssize;
int indegree[100001];

void dfs(int a){
	visit[a] = true;
	for(int b : adj[a]){
		if(visit[b]) continue;
		dfs(b);
	}
	S.push(a);
//	printf("push1 %d\n", a);//debug
	return;
}

void rdfs(int now){
	visit[now] = true;
	group[now] = ssize;
//	printf("%d: %d\n", ssize, now);//debug
	for(int next : radj[now]){
		if(visit[next]) continue;
		rdfs(next);
	}
	return;
}

int main()
{
	int i, res;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		
		//------clear------------------------
		
		adj.clear();
		adj.resize(N+1);
		radj.clear();
		radj.resize(N+1);
		while(!S.empty()) S.pop();

		ssize = 0;
		res = 0;
		memset(indegree, 0, sizeof(indegree));
		memset(group, 0, sizeof(group));

		//-------clear-------------------------

		for(i = 0 ; i < M ; i++){
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
		
		for(i = 1; i <= N ; i++){
			for(int j : adj[i]){
				if(group[i] == group[j]) continue;
			//	printf("%d-%d\n", group[i], group[j]);//debug
				indegree[group[j]]++;
			}
		}
		for(i = 0; i < ssize; i++)
			if(!indegree[i]) {
				//printf("%d\n", i);//debug
				res++;
			}
		printf("%d\n", res);
	}
	return 0;
}
