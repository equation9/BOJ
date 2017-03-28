/*7576번 토마토(C++11)*/
#include <cstdio>
#include <algorithm>
#include <queue>

std::queue<std::pair<int, int> > Q;
int N, M, Tomato[1001][1001], Max=1, tm;

void print()
{
	printf("==================\n");
	for(int i = 0 ; i < N ; i++)
	{
		for(int j = 0 ; j < M ; j++)
		{
			printf("%d ", Tomato[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &M, &N);
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < M ; j++)
		{
			scanf("%d", &Tomato[i][j]);
			if(Tomato[i][j] != -1) tm++;
			if(Tomato[i][j] == 1) Q.push( {i, j} );
		}
	}
	while(!Q.empty())
	{
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();
		tm--;
		/*printf("(%d, %d)tm : %d\n", i, j, tm);
		print();
*/
		if(i > 0 && !Tomato[i-1][j]) 
		{
			Tomato[i-1][j] = Tomato[i][j]+1;
			Max = std::max(Max, Tomato[i-1][j]);
			Q.push( {i-1, j} );
		}
		if(i < N-1 && !Tomato[i+1][j])
		{
			Tomato[i+1][j] = Tomato[i][j]+1;
			Max = std::max(Max, Tomato[i+1][j]);
			Q.push( {i+1, j} );
		}
		if(j > 0 && !Tomato[i][j-1])
		{
			Tomato[i][j-1] = Tomato[i][j]+1;
			Max = std::max(Max, Tomato[i][j-1]);
			Q.push( {i, j-1} );
		}
		if(j < M-1 && !Tomato[i][j+1])
		{
			Tomato[i][j+1] = Tomato[i][j]+1;
			Max = std::max(Max, Tomato[i][j+1]);
			Q.push( {i, j+1} );
		}
	}
	printf("%d\n", !tm ? Max-1 : -1);
	return 0;
}
