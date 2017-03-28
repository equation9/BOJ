/*2644번 촌수계산(C++11)*/
#include <cstdio>

int People[101][101], N, a1, a2;
bool visited[101];

int Kinship(int who, int cnt)
{
	int i, tcnt=0;
	if(who == a2)
		return cnt;
	for(i = 1 ; i <= N ; i++)
	{
		if(People[who][i]==1 && !People[a1][i])
		{
			People[a1][i] = cnt+1;
			People[i][a1] = cnt+1;
			//printf("%d -> %d\n", a1, i);
			tcnt += Kinship(i, cnt+1);
		}
	}
	return tcnt;
}

int main()
{
	int i, j, cnt=0;
	scanf("%d %d %d %d", &N, &a1, &a2, &cnt);
	while(cnt--)
	{
		scanf("%d %d", &i, &j);
		People[i][j]++;
		People[j][i]++;
	}
	for(i = 1 ; i <= N ; i++)
	{
		if(People[a1][i])
		{
			cnt += Kinship(i, 1);
		}
	}
	if(!cnt)
		cnt = -1;
	printf("%d\n", cnt);
	return 0;
}
