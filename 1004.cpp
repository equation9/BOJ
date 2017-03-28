/*1004번 어린 왕자(C++)*/
#include <cstdio>
#include <cmath>

double Dist(int x1, int y1, int x2, int y2)
{
	return sqrt(pow((double)(x1-x2), 2.0)+pow((double)(y1-y2), 2.0));
}

int main()
{
	int T, cnt;
	int sx, dx, sy, dy;
	int N, x, y;
	double r, dis1, dis2;
	scanf("%d", &T);
	while(T--)
	{	
		cnt=0;
		scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
		scanf("%d", &N);
		/*입력이 주어질 때마다 행성계가 출발지와 목적지를 포함하고 있는지 확인함*/
		while(N--)
		{
			scanf("%d %d %lf", &x, &y, &r);
			dis1 = Dist(sx, sy, x, y);
			dis2 = Dist(dx, dy, x, y);
			if((dis1 < r && dis2 > r) || (dis1 > r && dis2 < r))
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
