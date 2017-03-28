/*6064번 카잉 달력(C++)*/
#include <cstdio>

bool END_FLAG;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int T;
	int M, N, x, y, sx, sy, cnt, lcm;
	scanf("%d", &T);
	while(T--)
	{
		END_FLAG = false;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		sx = x;
		sy = y;
		cnt = 1;
		lcm = M*N / gcd(M, N);
		while(sx <= lcm || sy <= lcm)
		{
			if(sx == sy)
			{
				cnt = sx;
				END_FLAG = true;
				break;
			}
			else if(sx > sy)
			{
				sy += N;
			}
			else
			{
				sx += M;
			}
		}
		printf("%d\n", END_FLAG ? cnt : -1);
	}
	return 0;
}
