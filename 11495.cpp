/*11495번 격자 0 만들기(C++11)*/
/*네트워크 플로우*/
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using std::queue;
using std::vector;

#define MAX_N 50
#define MAX_V (MAX_N*MAX_N+2)
#define S (MAX_V-2)
#define E (MAX_V-1)
#define _INF 87654321
int map[51][51], Cost[MAX_V][MAX_V], F[MAX_V][MAX_V], N, M;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
	int T, i, j, pubg, flow;
	scanf("%d", &T);
	while(T--)
	{
		/*입력*/
		scanf("%d %d", &N, &M);

		pubg = 0;
		memset(F, 0, sizeof(F));
		memset(Cost, 0, sizeof(Cost));

		for(i = 0 ; i < N ; i++)
		{
			for(j = 0; j < M ; j++)
			{
				scanf("%d", &map[i][j]);
				pubg += map[i][j];
			}
		}

		/*간선 연결*/
		vector<int> adj[5010]; //합이 짝수, 홀수인 점 나눠서 그래프 
		for(i = 0 ; i < N ; i++)
		{
			for(j = 0; j < M ; j++)
			{
				int now = MAX_N*i+j; //각 위치를 숫자로 변환
				if(i%2 == j%2) //합이 짝수면 S와 연결
				{
					//printf(".(%d)=%d=(%d)\n",S, map[i][j], now); //디버그
					adj[now].push_back(S);
					adj[S].push_back(now);
					Cost[S][now] = map[i][j];

					for(int k = 0 ; k < 4 ;k++)
					{
						int ni = i+dy[k];
						int nj = j+dx[k];
						if(ni<0 || nj<0 || ni>=N || nj>=M) continue;
						int next=MAX_N*ni + nj;
						adj[now].push_back(next);
						adj[next].push_back(now);
						Cost[now][next] = _INF;
					}
				}
				else //합이 홀수
				{
					adj[E].push_back(now);
					adj[now].push_back(E);
					Cost[now][E] = map[i][j];
				}
			}
		}

		/*네트워크 플로우*/
		int prev[MAX_V];
		int sum = 0;
		while(1)
		{
			std::fill(prev, prev+MAX_V, -1);
			queue<int> Q;
			Q.push(S);

			while(!Q.empty() && prev[E] == -1)
			{
				int now = Q.front();
				Q.pop();
				for(int next : adj[now])
				{
					if(prev[next] == -1 && Cost[now][next]-F[now][next] > 0)
					{
						//printf("%d->%d\n", now, next); //디버그
						prev[next] = now;
						Q.push(next);
					}
				}
			}
			if(prev[E] == -1) break;

			flow = _INF;
			for(i = E ; i != S ; i = prev[i])
				flow = std::min(flow, Cost[prev[i]][i] - F[prev[i]][i]);
			for(i = E ; i != S ; i = prev[i])
			{
				//printf("%d->%d\n", i, prev[i]); //디버그
				F[prev[i]][i] += flow;
				F[i][prev[i]] -= flow;
			}
			sum += flow;
		}
		printf("%d\n", pubg - sum);
	}
	return 0;

}
