/*11971번 속도 위반(C++11)*/
#include <cstdio>

int limit[1000][2];

int main()
{
	int N, M, i, res = 0, a, b;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < N ; i++)
		scanf("%d %d", &limit[i][0], &limit[i][1]);
	i = 0;
	while(M--)
	{
		scanf("%d %d", &a, &b);
		//printf("\na: %d limit[%d][0] = %d\n", a, i, limit[i][0]);
		while(a >= limit[i][0])
		{
			if(limit[i][1] < b)
			{
				if(b - limit[i][1] > res)
				{
					res = b - limit[i][1];
				}
			}
			a -= limit[i][0];
			i++;
			//printf("\na: %d limit[%d][0] = %d\n", a, i, limit[i][0]);
			if(!a)
				break;
		}
		//printf("\na: %d limit[%d][0] = %d\n", a, i, limit[i][0]);
		if(a)	
		{
			limit[i][0] -= a;
			if(limit[i][1] < b)
			{
				if(b - limit[i][1] > res)
				{
					res = b - limit[i][1];
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
