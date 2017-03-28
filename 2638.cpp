/*2638번 치즈(C++11)*/
#include <cstdio>

int Cheese[100][100], MeltCheese[100][100], R, C;

void Copy(int ar1[100][100], int ar2[100][100])
{
	int i, j;
	for(i = 0 ; i < R ; i++)
	{
		for(j = 0 ; j < C ; j++)
			ar1[i][j] = ar2[i][j];
	}
	return;
}

void print() //디버깅용
{
	int i, j;
	printf("\n");
	for(i = 0 ; i < R ; i++)
	{
		for(j = 0 ; j < C ; j++)
		{
			printf("%d ", MeltCheese[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int Check(void)
{
	int i, j, sum=0;
	for(i = 0 ; i < R ; i++)
	{
		for(j = 0 ; j < C ; j++)
		{
			if(!Cheese[i][j])
				sum++;
		}
	}
	if(sum == R*C)
		return 1;
	return 0 ;
}

void Space(int y, int x)
{
	Cheese[y][x] = 2;
	if(y > 0 && !Cheese[y-1][x]) Space(y-1, x);
	if(x > 0 && !Cheese[y][x-1]) Space(y, x-1);
	if(y < R-1 && !Cheese[y+1][x]) Space(y+1, x);
	if(x < C-1 && !Cheese[y][x+1]) Space(y, x+1);
	return;
}

void Melt(int y, int x)
{
	int cnt=0;
	if(y > 0 && Cheese[y-1][x] == 2) cnt++;
	if(x > 0 && Cheese[y][x-1] == 2) cnt++;
	if(y < R-1 && Cheese[y+1][x] == 2) cnt++;
	if(x < C-1 && Cheese[y][x+1] == 2) cnt++;
	
	if(cnt >= 2)
		MeltCheese[y][x] = 0;
	return;
}

int main()
{
	int i, j, cnt=0;
	bool tmp;
	scanf("%d %d", &R, &C);
	for(i = 0 ; i < R; i++)
	{
		for(j = 0 ; j < C ; j++)
		{
			scanf("%d", &Cheese[i][j]);
			MeltCheese[i][j] = Cheese[i][j];
		}
	}
	while(1)
	{
		if(Check())
		{
			printf("%d\n", cnt);
			return 0;;
		}
		Space(0, 0);
		//print();	//디버깅용
		for(i = 0 ; i < R ; i++)
		{
			for(j = 0 ; j < C ; j++)
			{
				if(Cheese[i][j] == 1)
					Melt(i, j);
			}
		}
		Copy(Cheese, MeltCheese);
		cnt++;
	}
}
