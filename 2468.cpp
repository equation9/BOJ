/*2468번 안전 영역(C++)*/
#include <cstdio>
#include <cstring>

int cnt[101], area[100][100], N;

void remove(char tmp[100][100], int x, int y)
{
	tmp[x][y] = 'o';
	if(x > 0 && tmp[x-1][y] == '*')
		remove(tmp, x-1, y);
	if(y > 0 && tmp[x][y-1] == '*')
		remove(tmp, x, y-1);
	if(x < N-1 && tmp[x+1][y] == '*')
		remove(tmp, x+1, y);
	if(y < N-1 && tmp[x][y+1] == '*')
		remove(tmp, x, y+1);
	return;
}

int check_safe(int n)
{
	int i, j, count=0;
	char tmp[100][100];
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < N ; j++)
		{
			if(area[i][j] > n)
			{
				tmp[i][j] = '*';
			}
			else
				tmp[i][j] = 'o';
		}
	}

	for(i = 0 ; i < N ; i++)
		for(j = 0 ; j < N ; j++)
		{
			if(tmp[i][j] == '*')
			{
				remove(tmp, i, j);
				count++;
			}
		}
	return count;
}

int main()
{
	int i, j, res=0, tmp;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
		for(j = 0 ; j < N ; j++)
		{
			scanf("%d", &area[i][j]);
			cnt[area[i][j]]++;
		}
	for(i = 0 ; i <= 100 ; i++)
	{
		if(!cnt[i] && i)
			continue;
		tmp = check_safe(i);
		if(tmp > res)
			res = tmp;
	}
	printf("%d\n", res);
	return 0;
}
