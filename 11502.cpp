/*11502번 세 개의 소수 문제(C++11)*/
#include <cstdio>

int N[1001], _END_FLAG;

int main()
{
	int T, i, j, k, K, tmp;
	for(i = 2 ; i <= 1000 ; i++)
	{
		if(N[i])
			continue;
		for(j = 2*i ; j <= 1000 ; j += i)
		{
			N[j] = 1;
		}
	}

	scanf("%d", &T);
	while(T--)
	{
		_END_FLAG = 0;
		scanf("%d", &K);
		for(i = 2 ; i <= K ; i++)
		{
			if(N[i])
				continue;
			tmp = K;
			tmp -= i;
			for(j = i ; j <= K ; j++)
			{
				k = tmp-j;
				if(N[j] || k < 2 || N[k])
					continue;
				else
				{
					printf("%d %d %d\n", i, j, tmp-j);
					_END_FLAG = 1;
					break;
				}
			}
			if(_END_FLAG)
				break;
		}
		if(!_END_FLAG)
			printf("0\n");
	}
	return 0;
}
