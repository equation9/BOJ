/*2580번 스도쿠(C) 프로젝트파일 긁어왔다 개꿀*/
#include <stdio.h>
#include <stdlib.h>

static int Sudoku[9][9]; //문제 행렬
static int solved_Sudoku[9][9]; //완성된 스도쿠 저장 행렬
static int is_it_over; //종료 키워드(칸이 다 채워졌는가 -> 1: 종료 0: 계속진행)

void Print_Map(int map[9][9]); //스도쿠 출력
void Read_Map(void);
void init_Map(void);

void Solve_sudoku(void); //스도쿠 풀기 메인함수
int sub_num(int x, int y, int n); //숫자 대입
int check_num(int x, int y, int n); //대입가능한지 판별

int main(){
	Read_Map();
	Solve_sudoku();
	Print_Map(solved_Sudoku);
	return 0;
}

void Solve_sudoku(){
	int i, j, n;
	is_it_over = 0;
	init_Map(); //초기화

	i = j = 0;
	while(solved_Sudoku[i][j]) //스도쿠 시작지점 찾기
	{
		if(j == 8)
		{
			if(i == 8)//이미 완성된 수도쿠
			{
				is_it_over++;
				return;
			}
			i++;
			j = 0;
		}
		else //줄 바꿈
			j++;
	}
	for(n = 1 ; n <= 9 ; n++) //한 칸에 숫자 대입
	{
		if(is_it_over)
			return;
		sub_num(i, j, n);
	}
	return;
}

int check_num(int x, int y, int n)
{
	int i, j;
	/*세로줄 체크*/
	for(i = 0 ; i < 9 ; i++)
		if(solved_Sudoku[i][y] == n)
			return 1;
	/*가로줄 체크*/
	for(j = 0 ; j < 9 ; j++)
		if(solved_Sudoku[x][j] == n)
			return 1;
	/*3x3 블럭 체크*/
	for(i = (x/3)*3 ; i < (x/3)*3 + 3 ; i++)
	{
		for(j = (y/3)*3 ; j < (y/3)*3 + 3 ; j++)
		{
			if(solved_Sudoku[i][j] == n)
				return 1;
		}
	}
	return 0; //세 가지 경우에 다 해당하지 않으므로 숫자 사용 가능
}

int sub_num(int x, int y, int n)
{
	//printf("%d ", 9 * x + y + 1);
	
	int nx=x, ny=y, i, cnt=0;
	if(!check_num(x, y, n)) //숫자 넣기 가능
	{
		if(!solved_Sudoku[x][y]) //칸이 비어있음
		{
			solved_Sudoku[x][y] = n;
			/*printf("\n-\n");
			Print_Map(solved_Sudoku);
			printf("-\n");*/
		}
		while(1) //다음 대입을 수행할 칸을 탐색(문제로 주어진 숫자 뛰어넘기)
		{
			if(ny == 8)
			{
				if(nx == 8) //스도쿠를 완성함
				{
					is_it_over++;
					return 1;
				}
				else //줄바꿈
				{
					nx++;
					ny=0;
				}
			}
			else
				ny++;
			if(!Sudoku[nx][ny])
				break;
		}
		for(i = 1 ; i <= 9 ; i++)
		{
			if(is_it_over)
				return 1;	
			cnt += sub_num(nx, ny, i);
		}
	}
	else //숫자 넣기 불가능
		return 0;

	if(!cnt) //다음칸에 숫자를 넣을 수 없음
	{
		solved_Sudoku[x][y] = Sudoku[x][y];
		return 0;
	}
	return 1;
}

void init_Map(void)
{
	int i, j;
	for(i = 0 ; i < 9 ; i++)
		for(j = 0 ; j < 9 ; j++)
			solved_Sudoku[i][j] = Sudoku[i][j];
	return;
}

void Print_Map(int map[9][9]){
	int i, j, color;
	for(i = 0 ; i < 9 ; i++){
		for(j = 0 ; j < 9 ;j++)
			printf("%d ", map[i][j]);
		printf("\n");	
	}
}

void Read_Map(void){
	int i, j;
	for(i = 0 ; i < 9 ; i++)
		for(j = 0 ; j < 9 ; j++)
			scanf("%d", &Sudoku[i][j]);
	init_Map();
	return;
}
