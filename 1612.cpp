/*1612번 가지고 노는1(C++11)*/
#include <cstdio>

int CNT[1000001];

int main()
{
	long long int N, i, tmp, ONE, cnt=1;
	scanf("%lld", &N);
	tmp = 1;
	while(tmp % N)
	{
		tmp %= N;
		if(CNT[tmp])
		{
			cnt = -1;
			break;
		}
		CNT[tmp]++;
		tmp = tmp*10 + 1;
		cnt++;
	}
	printf("%lld\n", cnt);
	return 0;
}
