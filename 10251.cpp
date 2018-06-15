/*10251번 운전 면허 시험(C++11)*/
#include <iostream>
#include <cstring>
using namespace std;

struct Point{
	int x;
	int y;
};

int T, M, N, L, G;
int mem[101][101][210][2];//[x][y][n][d] x y 까지 n번 방향틀고 d(0아래, 1오른쪽) 방향
Point P[101][101]; // [i][j] : (i->i+1, j) , (i , j->j+1)

int main()
{
	int i, j, k, res, tmp1, tmp2;
	cin>> T;
	while(T--)
	{
		cin>> M >> N >> L >> G;
		for(i = 0; i < M; i++)
			for(j = 0; j < N-1; j++)
				cin>> P[i][j].x;
		for(i = 0; i < M-1; i++)
			for(j = 0; j < N; j++)
				cin>> P[i][j].y;
		memset(mem, -1, sizeof(mem));

		mem[0][0][0][0] = 0;
		mem[0][0][0][1] = 0;

		for(i = 0 ; i < M ; i++){ //x
			for(j = 0; j < N; j++){ //y
				for(k = 0; k <= 200; k++){
					if(mem[i][j][k][0] != -1){
						tmp1 = mem[i+1][j][k][0];
						tmp2 = mem[i][j][k][0] + P[i][j].y;
						if((i < M-1) && ((tmp1 == -1) || (tmp1>tmp2 ))) 
							mem[i+1][j][k][0] = tmp2;

						tmp1 = mem[i][j+1][k+1][1];
						tmp2 = mem[i][j][k][0] + P[i][j].x;
						if((j < N-1) && ((tmp1 == -1) || (tmp1>tmp2))) 
							mem[i][j+1][k+1][1] = tmp2;
					}

					if(mem[i][j][k][1] != -1){
						tmp1 = mem[i+1][j][k+1][0];
						tmp2 = mem[i][j][k][1] + P[i][j].y;
						if((i < M-1) && ((tmp1 == -1) || (tmp1>tmp2))) 
							mem[i+1][j][k+1][0] = tmp2;
						
						tmp1 = mem[i][j+1][k][1];
						tmp2 = mem[i][j][k][1] + P[i][j].x;
						if((j < N-1) && ((tmp1 == -1) || (tmp1>tmp2)))
							mem[i][j+1][k][1] = tmp2;
					}
				}
			}
		}

		res = -1;
		for(k = 200; k > 0; k--){
			if((mem[M-1][N-1][k][0] != -1) && (mem[M-1][N-1][k][0] <= G))
				res = k;
			if((mem[M-1][N-1][k][1] != -1) && (mem[M-1][N-1][k][1] <= G)) 
				res = k;
		}
		if(res != -1) res = (M+N-2)*L + res;
		cout<< res <<"\n";
	}
	return 0;
}
