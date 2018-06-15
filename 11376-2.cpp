/*11376번 열혈강호 2(C++11)*/
/*재*/
#include <cstdio>
#include <vector>
#include <cstring>

int N, M;
int matchA[2001], matchB[1001]; //직원 a가 있으면 a 와 a+N 둘로 나눈다 
std::vector<int> adj[1001];
bool visit[1001];

bool bfs(int a){
	visit[a] = true;
	for(int b : adj[a]){
		if(!matchA[b] || (!visit[matchA[b]] && bfs(matchA[b]))){
			matchB[a] = b;
			matchA[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	int i, j, res = 0;
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N; i++){
		int a, b;
		scanf("%d", &a);
		for(j = 0; j < a; j++){
			scanf("%d", &b);
			adj[b].push_back(i);
			adj[b].push_back(N+i);
		}
	}
	for(i = 1; i <= M; i++){
		if(!matchB[i]){
			memset(visit, false, sizeof(visit));
			if(bfs(i)) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
