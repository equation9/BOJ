/*2458번 키 순서(C++11)*/
#include <cstdio>
#include <cstring>

int N;
bool AsmallB[501][501], AbigB[501][501], visited[501];

void dfs(bool ar[501][501], int i, int j)
{
	int b;
	visited[j] = true;
	for(b = 1 ; b <= N ; b++)
	{
		if(ar[j][b] && !visited[b])
		{
			ar[i][b] = true;
			//printf("%d < %d\n", i, b);
			dfs(ar, i, b);
		}
	}
	return;
}

int main()
{
	int i, j, cnt, tmp;
	scanf("%d %d", &N, &cnt);
	while(cnt--)
	{
		scanf("%d %d", &i, &j);
		AsmallB[i][j] = true;
		AbigB[j][i] = true;
	}
	cnt++;
	for(i = 1 ; i <= N ; i++)
	{
		memset(visited, false, sizeof(visited));
		tmp = 0;
		for(j = 1 ; j <= N ; j++)
		{
			if(AsmallB[i][j])
			{
				dfs(AsmallB, i , j);
			}
			if(AbigB[i][j])
			{
				dfs(AbigB, i , j);
			}
		}
		for(j = 1 ; j <= N ; j++)
		{
			if(AsmallB[i][j] || AbigB[i][j])
			{
				tmp++;
			}
		}
		if(tmp == N-1)
		{
			cnt++;
			//printf("=%d\n", i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}
