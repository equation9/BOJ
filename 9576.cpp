/*9576번 책 나눠주기(C++11)*/
/*이분 매칭*/
#include <cstdio>
#include <cstring>
#include <vector>

int T;
int N, M;
int res;
int match[1001];
bool visit[1001];
std::vector<std::vector<int> > adj;

bool bfs(int a){
	visit[a] = true;
	for(int b : adj[a]){
		if(!visit[match[b]] && (!match[b] || bfs(match[b]))){
			match[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	int i, j;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &M);
		memset(match, 0, sizeof(match));
		adj.clear();
		adj.resize(M+1);
		res = 0;

		for(i = 1; i <= M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			for(j = a; j <= b; j++)
				adj[i].push_back(j);
		}
		for(i = 1; i <= M; i++){
			memset(visit, 0, sizeof(visit));
			if(bfs(i)) res++;
		}
		printf("%d\n", res);
	}
}
