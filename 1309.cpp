/*1309번 동물원(C++11)*/
#include <cstdio>
#include <cstring>

int Paint[100001][3]; //0 아무 것도 안들어감 1 왼쪽 2 오른쪽

int dp(int y, int x)
{
	if(Paint[y][x] != -1) return Paint[y][x];

	int i, j;
	i = (x+1)%3;
	j = (x+2)%3;
	return Paint[y][x] = (dp(y-1, i)+dp(y-1,j) + (x==0 ? dp(y-1,0) : 0))%9901;
}

int main()
{
	int N, i;
	scanf("%d", &N);
	memset(Paint, -1, sizeof(Paint));
	Paint[0][0] = Paint[0][1] = Paint[0][2] = 1;
	printf("%d\n", (dp(N-1, 0)+dp(N-1,1)+dp(N-1,2))%9901);
	return 0;
}
