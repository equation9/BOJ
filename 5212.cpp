/*5212번 지구 온난화(C++11)*/
#include <cstdio>

char Map[10][11];
char new_Map[10][11];
int R, C, mx, my, Mx, My;

void check_around(int y, int x)
{
	int cnt = 0;
	if((x == 0) || (Map[y][x-1] == '.'))
		cnt++;
	if((x == C-1) || (Map[y][x+1] == '.'))
		cnt++;
	if((y == 0) || (Map[y-1][x] == '.'))
		cnt++;
	if((y == R-1) || (Map[y+1][x] == '.'))
		cnt++;

	if(cnt >= 3)
		new_Map[y][x] = '.';
	else
	{
		new_Map[y][x] = 'X';
		if(Mx < x)
			Mx = x;
		if(My < y)
			My = y;	
		if(mx > x)
			mx = x;
		if(my > y)
			my = y;
	}
	return;
}

void sink_(void)
{
	int i, j;
	for(i = 0 ; i < R ; i++)
	{
		for(j = 0 ; j < C ; j++)
		{
			if(Map[i][j] == 'X')
			{
				check_around(i, j);
			}
			else
				new_Map[i][j] = Map[i][j];
		}
	}
}


int main()
{
	int i, j;
	scanf("%d %d", &R, &C);
	mx = C-1;
	my = R-1;
	Mx = 0;
	My = 0;
	for(i = 0 ; i < R ; i++)
		scanf("%s", Map[i]);
	sink_();
	for(i = my ; i <= My ; i++)
	{
		for(j = mx ; j <= Mx ; j++)
			printf("%c", new_Map[i][j]);
		printf("\n");
	}
	return 0;
}
