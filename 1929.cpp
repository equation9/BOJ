/*1929번 소수 구하기(C++11)*/
#include <cstdio>

bool ar[1000001];

int main()
{
	int N, M, i, j;
	ar[0] = ar[1] = true;
	for(i = 2 ; i < 1000001 ; i++)
	{
		if(ar[i])
			continue;
		for(j = 2 ; j*i <= 1000000 ; j++)
		{
			ar[j*i] = true;
		}
	}
	scanf("%d %d", &M, &N);
	for(i = M ; i <= N ; i++)
	{
		if(!ar[i])
		{
			printf("%d\n", i);
		}
	}

	return 0;
}
