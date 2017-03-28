/*1668번 트로피 진열(C++11)*/
#include <cstdio>

int trophy[50];

int main()
{
	int N, i, bigger=0, cnt=0;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &trophy[i]);
		if(trophy[i] > bigger)
		{
			cnt++;
			bigger = trophy[i];
		}
	}
	printf("%d\n", cnt);
	cnt = bigger = 0;
	for(i = N-1 ; i >= 0 ; i--)
	{
		if(trophy[i] > bigger)
		{
			cnt++;
			bigger = trophy[i];
		}
	}
	printf("%d\n", cnt);
	return 0;
}
