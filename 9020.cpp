/*9020번 골드바흐의 추측(C++11)*/
#include <cstdio>

int N[10001];

int main()
{
	int T, i, j, K, ress, resl;
	for(i = 2 ; i <= 10000 ; i++)
	{
		if(N[i])
			continue;
		for(j = 2*i ; j <= 10000 ; j += i)
		{
			N[j] = 1;
		}
	}

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &K);
		for(i = 2 ; i <= K/2 ; i++)
		{
			if(N[i])
				continue;
			j = K-i;
			if(!N[j])
			{
				ress = i;
				resl = j;
			}
		}
		printf("%d %d\n", ress, resl);
	}
	return 0;
}
