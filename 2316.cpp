/*2316번 도시 왕복하기(C++11)*/
/*네트워크 플로우*/
/*1번과 2번의 최대 유량*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N, P;
int map[802][802]; 
queue<int> Q;
int pr[802];

int main()
{
	int i;
	scanf("%d %d", &N, &P);
	for(i = 1; i <= N; i++)
		map[i][N+i] = 1;
	map[1][N+1] = map[2][N+2] = 87654321;

	for(i = 0; i < P; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		map[N+a][b] = map[N+b][a] = 1;
	}

	int res = 0;
	while(1){
		memset(pr, -1, sizeof(pr));
		pr[1] = 1;
		Q.push(1);
		while(!Q.empty() && pr[N+2] == -1)
		{
			int now = Q.front();
			Q.pop();
			for(i = 1; i <= 2*N; i++){
				if(!map[now][i] || pr[i] != -1) continue;
			//	printf("%d -> %d\n", now%N, i%N);//debug
				Q.push(i);
				pr[i] = now;
			}
		}
		if(pr[N+2] == -1) break;//더이상 보낼 수 없음
		for(i = N+2; i != pr[i]; i = pr[i]){
		//	printf("%d-%d ,%d, %d\n", pr[i], i, map[pr[i]][i], map[i][pr[i]]);//debug
			map[pr[i]][i]--;
			map[i][pr[i]]++;
		}
		res++;
		while(!Q.empty()) Q.pop();//flush
	}
	printf("%d\n",res);
	return 0;
}
