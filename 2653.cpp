/*2653번 안정된 집단(C++11)*/
#include <cstdio>
#include <vector>

int relate[101][101], n, t;
bool visit[101];
std::vector<int> V[101];
std::vector<int>::iterator it;

int main()
{
	int i, j, k;
	scanf("%d", &n);
	for(i = 1; i <= n ; i++)
		for(j = 1 ; j <= n ; j++)
			scanf("%d", &relate[i][j]);
	for(i = 1 ; i <= n ; i++)
		for(j = i+1 ; j<= n ; j++)
			if(relate[i][j] != relate[j][i]) 
				return 0 | printf("0\n");
//	printf("1====\n");//디버그
	for(i = 1 ; i <= n ; i++)
	{
		if(visit[i]) continue;
		visit[i] = true;
		V[t].push_back(i);
		for(j = 1 ; j <= n ; j++)
		{
			if(visit[j]) continue;
			if(!relate[i][j])
			{
				for(k = 1 ; k <= n ; k++)
					if(relate[i][k] != relate[j][k]) return 0 | printf("0\n");
				V[t].push_back(j);
				visit[j] = true;
			}
		}
		t++;
	}
//	printf("2====\n");//디버그
	for(i = 0 ; i < t ; i++)
	{
		if(V[i].size() < 2)
			return 0 | printf("0\n");
	}
//	printf("3====\n");//디버그
	printf("%d\n", t);
	for(i = 0 ; i < t ; i++)
	{
		for(it = V[i].begin() ; it != V[i].end() ; it++)
			printf("%d ", *it);
		printf("\n");
	}
	return 0;
}
