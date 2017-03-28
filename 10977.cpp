/*10977번 음식 조합 세기(C++11)*/
#include <cstdio>
#include <cstring>

int M, N, Dist[1000001];

int GetPattern(int n)
{
	int i, j, res=0;
	for(i = 0 ; i < n ; i++)
	{
		res += Dist[i];
	//	printf("res : %d\n", res);
		for(j = i+n ; j < N ; j += n)
		{
			if(Dist[j] != Dist[j-n])
				return 0;
		}
	}
	return res;
}

int main()
{
	int T, cnt=0, tmp, prev, i, start;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &M, &N);
		scanf("%d", &prev);
		start = prev;
		tmp = start;
		for(i = 0 ; i < N-1 ;i++)
		{
			scanf("%d", &tmp);
			Dist[i] = tmp - prev;
			prev = tmp;
		}
		Dist[i] = M-tmp+start;

		/*for(i = 0 ; i < N ; i++)
		{
			printf("%d ", Dist[i]);
		}
		printf("\n\n");*/
		for(i = 1 ; i <= N ; i++)
		{
			if(N % i)
				continue;
			cnt = GetPattern(i);
			if(cnt)
			{
				printf("%d\n", cnt);
				break;
			}
		}
	}
	return 0;
}
