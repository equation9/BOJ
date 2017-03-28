/*2798번 블랙잭(C++11)*/
#include <cstdio>
#include <cmath>

int card[100000];

int main()
{
	int N, M, i, j, k, res=0, tmp;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < N ; i++)
		scanf("%d", &card[i]);
	for(i = 0 ; i < N-2 ; i++)
	{
		for(j = i+1 ; j < N-1 ; j++)
		{
			for(k = j+1 ; k < N ; k++)
			{
				tmp = card[i]+card[j]+card[k];
				if(tmp > M)
					continue;
				else if(tmp == M)
				{
					printf("%d\n", tmp);
					return 0;
				}
				else if(tmp > res)
					res = tmp;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
