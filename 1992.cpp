/*1992번 쿼드트리(C++11)*/
#include <cstdio>

char map[65][65];
int N;

char full(int y, int x, int n)
{
	int i, j, cnt1=0, cnt0=0;
	for(i = 0 ; i < n ;i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			if(map[y+i][x+j] == '1')
				cnt1++;
			else
				cnt0++;
		}
	}
	if(!cnt0)
		return '1';
	else if(!cnt1)
		return '0';
	else
		return '2';
}

void Zip(int y, int x , int n)
{
	int Mid = n/2, tmp;
	if(full(y, x, n) == '2')
	{
		printf("(");
		Zip(y, x, Mid);
		Zip(y, x+Mid, Mid);
		Zip(y+Mid, x, Mid);
		Zip(y+Mid, x+Mid, Mid);
		printf(")");
	}
	else
		printf("%c", full(y, x, n));
}

int main()
{
	int i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%s", map[i]);
	}
	Zip(0, 0, N);
	printf("\n");
	return 0;
}
