/*14433번 한조 대기 중(C++11)*/
#include <cstdio>
#include <cstring>
#include <vector>
using std::vector;

bool visit[301];
int N, M, K[2], loop, A[301], B[301], res[2];
vector<int> V[2][301];

bool dfs(int a)
{
	visit[a] = true;
	for(int b : V[loop][a])
	{
		if(!B[b] || !visit[B[b]] && dfs(B[b]))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}


int main()
{
	int i, j, cnt, a, b;
	scanf("%d %d %d %d", &N ,&M, &K[0], &K[1]);
	for(loop = 0 ; loop < 2 ; loop++)
	{
		for(i = 0 ; i < K[loop] ; i++)
		{
			scanf("%d %d", &a, &b);
			V[loop][a].push_back(b);
		}
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for(i = 1 ; i <= N ; i++)
		{
			if(!A[i])
			{
				memset(visit, false, sizeof(visit));
				if(dfs(i)) res[loop]++;
			}
		}

	}
	printf("%s\n", res[0] < res[1] ? "네 다음 힐딱이" : "그만 알아보자");
	return 0;
}
