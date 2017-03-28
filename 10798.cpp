/*10798번 세로읽기(C++11)*/
#include <cstdio>
#define N 5

int cnt[5];

int main()
{
	char Input[5][16];
	int i, j;
	for(i = 0 ; i < N ; i++)
	{
		scanf("%s", Input[i]);
	}
	for(i = 0 ; i < 15 ; i++)
	{
		for(j = 0 ; j < N ; j++)
		{
			if(cnt[j])
				continue;
			if(Input[j][i] == '\0')
			{
				cnt[j]++;
				continue;
			}
			printf("%c", Input[j][i]);
		}
	}
	printf("\n");
	return 0;
}
