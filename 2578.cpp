/*2578번 빙고(C++11)*/
#include <cstdio>

int board[5][5];
bool END_FLAG;

void remove(int num)
{
	int i, j;
	for(i = 0 ; i < 5 ; i++)
		for(j = 0 ; j < 5 ; j++)
		{
			if(board[i][j] == num)
			{
				board[i][j] = 0;
				return;
			}
		}
	return;
}

int check_line(int x, int y, int command)
{
	int i;
	switch(command)
	{
		case 1 : //세로
			for(i = 0 ; i < 5 ; i++)
			{
				if(board[i][y] != 0)
					return 0;
			}
			break;
		case 2 : //가로
			for(i = 0 ; i < 5 ; i++)
			{
				if(board[x][i] != 0)
					return 0;
			}
			break;
		case 3 : //대각선 정방
			for(i = 0 ; i < 5 ; i++)
			{
				//printf("board[%d][%d] =  %d \n", i, i, board[i][i]);
				if(board[i][i] != 0)
					return 0;
			}
			break;
		case 4 : //대각선 역방
			for(i = 0 ; i < 5 ; i++)
			{
				if(board[i][4-i] != 0)
					return 0;
			}
			break;
	}
	return 1;
}

void Check_Bingo(void)
{
	int i, j, cnt=0;
	if(board[0][0] == 0)
		cnt += check_line(0, 0, 3);
	//printf("cnt = %d\n", cnt);
	if(board[0][4] == 0)
		cnt += check_line(0, 4, 4);
	//printf("cnt = %d\n", cnt);

	for(i = 0 ; i < 5 ; i++)
	{
		if(board[i][0] == 0)
			cnt += check_line(i, 0, 2);
	}
	//printf("cnt = %d\n", cnt);
	for(i = 0 ; i < 5 ; i++)
	{
		if(board[0][i] == 0)
			cnt += check_line(0, i, 1);
	}
	//printf("cnt = %d\n", cnt);
	if(cnt >= 3)
	{
		END_FLAG = true;
	}
	//printf("cnt = %d\n", cnt);
	return;
}

void print()
{
	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
			printf("%2d ", board[i][j]);
		printf("\n");
	}
		printf("\n");
}

int main()
{
	int i, j, tmp, cnt=0;
	for(i = 0 ; i < 5 ; i++)
		for(j = 0 ; j < 5 ; j++)
			scanf("%d", &board[i][j]);
	for(i = 1 ; i <= 25 ; i++)
	{
		scanf("%d", &tmp);
		/*printf("\n<%d>\n", cnt);
		print();
		printf("remove %d\n", tmp);*/
		remove(tmp);
		if(!END_FLAG)
		{
			cnt++;
			Check_Bingo();
		}
	}
	printf("%d\n", cnt);
	return 0;
}
