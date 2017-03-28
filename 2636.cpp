/*2636번 치즈(C++11)*/
#include <cstdio>

int R, C, Cheese[100][100], time, cnt;

void print()
{
	int i, j;
	printf("===========\n");
	for(i = 0 ; i < C ; i++)
	{
		for(j = 0 ; j < R ; j++)
		{
			printf("%d ", Cheese[i][j]);
		}
		printf("\n");
	}
	printf("===========\n");
}

int CheckEmpty()
{
	int i, j;
	for(i = 0 ; i < C ; i++)
	{
		for(j = 0 ; j < R ; j++)
		{
			if(Cheese[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

void Melting(int i, int j)
{
	if(i > 0)
	{
		if(Cheese[i-1][j] == 1)
		{
			Cheese[i-1][j] = -1;
		}
		else if(Cheese[i-1][j] == 0)
		{
			Cheese[i-1][j] = 2;
			Melting(i-1, j);
		}
	}
	if(j > 0)
	{
		if(Cheese[i][j-1] == 1)
		{
			Cheese[i][j-1] = -1;
		}
		else if(Cheese[i][j-1] == 0)
		{
			Cheese[i][j-1] = 2;
			Melting(i, j-1);
		}
	}
	if(i < C-1)
	{
		if(Cheese[i+1][j] == 1)
		{
			Cheese[i+1][j] = -1;
		}
		else if(Cheese[i+1][j] == 0)
		{
			Cheese[i+1][j] = 2;
			Melting(i+1, j);
		}
	}
	if(j < R-1)
	{
		if(Cheese[i][j+1] == 1)
		{
			Cheese[i][j+1] = -1;
		}
		else if(Cheese[i][j+1] == 0)
		{
			Cheese[i][j+1] = 2;
			Melting(i, j+1);
		}
	}
	return;
}

void MeltCheese()
{
	int i, j, tcnt=0;
	Melting(0, 0);
	time++;
	for(i = 0 ; i < C ; i++)
	{
		for(j = 0 ; j < R ; j++)
		{
			if(Cheese[i][j] == -1)
			{
				Cheese[i][j] = 0;
				tcnt++;
			}
			else if(Cheese[i][j] == 2)
			{
				Cheese[i][j] = 0;
			}
		}
	}
	//print();
	if(CheckEmpty())
	{
		printf("%d\n%d\n", time, cnt);
		return;
	}
	cnt -= tcnt;
	MeltCheese();
	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &C, &R);

	for(i = 0 ; i < C ; i++)
	{
		for(j = 0 ; j < R ; j++)
		{
			scanf("%d", &Cheese[i][j]);
			if(Cheese[i][j])
			{
				cnt++;
			}
		}
	}
	if(CheckEmpty())
	{
		printf("0\n0\n");
		return 0;
	}
	MeltCheese();
	return 0;
}
