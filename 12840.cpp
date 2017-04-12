/*12840번 창용이의 시계(C++11)*/
#include <cstdio>
#define _MAX 24*3600
int main()
{
	int h, m, s, Sum, N, q, a;
	scanf("%d %d %d %d", &h, &m, &s, &N);
	Sum = h*3600 + m*60 + s;
	while(N--)
	{
		scanf("%d", &q);
		switch(q)
		{
			case 1 :
				scanf("%d", &a);
				Sum += a;
				if(Sum > _MAX) Sum %= _MAX;
				break;
			case 2 :
				scanf("%d", &a);
				Sum -= a;
				while(Sum < 0) Sum += _MAX;
				break;
			default :
				printf("%d %d %d\n", Sum / 3600 , (Sum%3600) / 60 , Sum % 60);
				break;
		}
	}
	return 0;
}
