/*2960번 에라토스테네스의 체(C++11)*/
#include <cstdio>
#include <cstring>

int Num[1001], K, N;

int main()
{
	int i, j, cnt=0, n;
	scanf("%d %d", &N, &K);
	for(i = 2 ; i <= N ; i++)
	{
		if(Num[i])
			continue;
		for(j = 1 ; j <= N/i ; j++ )
		{
			n = j*i;
			if(!Num[n])
			{
				Num[n] = 1;
				cnt++;
			}
			if(cnt == K)
			{
				printf("%d\n", n);
				return 0;
			}
		}
	}

	return 0;
}
