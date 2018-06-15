/*2339번 석판 자르기(C++11)*/
#include <iostream>
#include <set>
using namespace std;

int N, Slate[21][21];

int DQ(int sy, int sx, int dy, int dx, int flag)
{
	if(sy == dy || sx == dx) return 0;

	int i, j;
	int res = 0;
	set<int> yp, xp;
	int df=0, cr=0; //불순물, 결정

	for(i = sy; i < dy ; i++){
		for(j = sx; j < dx; j++){
			if(Slate[i][j] == 1){
				df++;
				yp.insert(i);
				xp.insert(j);
			}
			else if(Slate[i][j] == 2)
				cr++;
		}
	}

	if(cr == 0) return 0;
	if(cr == 1) return !df;
	if(df == 0 ) return 0;

	if(flag != 1)
	{
		for(int x : xp){
			bool possible = true;
			for(i = sy; i < dy; i++){
				if(Slate[i][x] == 2){
					possible = false;
					break;
				}
			}

			if(possible)
				res += DQ(sy, sx, dy, x, 1) * DQ(sy,x+1, dy, dx, 1);
		}
	}
	if(flag != 2)
	{
		for(int y : yp){
			bool possible = true;
			for(i = sx; i < dx; i++){
				if(Slate[y][i] == 2){
					possible = false;
					break;
				}
			}

			if(possible)
				res += DQ(sy, sx, y, dx, 2) * DQ(y+1, sx, dy, dx, 2);
		}
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int i, j, res=0;
	int df = 0, cr = 0;
	cin>>N;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			cin>>Slate[i][j];
			if(Slate[i][j] == 1) df++;
			else if(Slate[i][j] == 2) cr++;
		}
	}
	res = DQ(0, 0, N, N, 0);
	if(!res) res = -1;
	cout<< res <<endl;
	return 0;
}
