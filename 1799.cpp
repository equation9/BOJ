/*1799번 비숍(C++11)*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, map[11][11];
int Bmax, Wmax; //Black_max, White_max
bool diag[22], rdiag[22]; //대각선, 역대각선

void black(int y, int x, int cnt)
{
	Bmax = max(Bmax, cnt);

	if(x > N){
		y++;
		x = 1 + y%2;
	}
	if(y > N) return;

	if(map[y][x] && !diag[y+x] && !rdiag[10+(y-x)]){
		diag[y+x] = true;
		rdiag[10+(y-x)] = true;

		black(y , x+2, cnt+1);

		diag[y+x] = false;
		rdiag[10+(y-x)] = false;
	}
	black(y, x+2, cnt);
	return;
}

void white(int y, int x, int cnt)
{
	Wmax = max(Wmax, cnt);

	if(x > N){
		y++;
		x = 1 + !(y%2);
	}
	if(y > N) return;

	if(map[y][x] && !diag[y+x] && !rdiag[10+(y-x)]){
		diag[y+x] = true;
		rdiag[10+(y-x)] = true;

		white(y , x+2, cnt+1);

		diag[y+x] = false;
		rdiag[10+(y-x)] = false;
	}
	white(y, x+2, cnt);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	int i, j;

	cin>> N;
	for(i = 1; i <= N; i++)
		for(j = 1; j <= N; j++)
			cin>> map[i][j];

	black(1,2,0);
	white(1,1,0);
	cout<< Bmax + Wmax <<endl;
	return 0;
}
