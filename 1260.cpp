/*1260번 DFS와 BFS(C++)*/
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

static int Vertex[1010][1010];
static int dcnt[1010];
static int bcnt[1010];
queue<int>q;//bfs용 큐

void DFS(int N, int V){
	int i;
	dcnt[V] = 1;
	printf("%d ", V);
	for(i = 1 ; i <= N ; i++)
		if(Vertex[V][i] && !dcnt[i])
			DFS(N, i);
}

void BFS(int N, int V){
	int now, i;
	q.push(V);
	bcnt[V] = 1;
	while(!q.empty()){
		now = q.front();
		printf("%d ", now);
		q.pop();
		for(i = 1 ; i <= N ; i++){
			if(Vertex[now][i] && !bcnt[i])
			{
				bcnt[i]++;
				q.push(i);
			}
		}
	}
}

int main(){
	int N, M, V;
	int a, b, i;
	scanf("%d %d %d", &N, &M, &V);
	for(i = 0 ; i < M ; i++){
		scanf("%d %d", &a, &b);
		Vertex[a][b] = 1;
		Vertex[b][a] = 1;
	}
	DFS(N, V);
	printf("\n");

	BFS(N, V);
	printf("\n");
	return 0;
}
