/*1644번 소수의 연속합(C++11)*/
#include <cstdio>

bool isitPrime[4000001];
int cnt, N, _MAX, s, e, Prime[4000000];

int main()
{
	int i, j, n;
	isitPrime[0] = isitPrime[1] = true;
	scanf("%d", &N);
	for(i = 2; i <= N ;i++)
	{
		if(isitPrime[i])
			continue;
		Prime[s++] = i;
		for(j = 2; i*j <= N ; j++)
		{
			isitPrime[i*j] = true;
		}
	}
	_MAX = s;
	s = 0;
	n = Prime[s];
	while(s <= e)
	{
		if(n == N)
		{
			cnt++;
			n -= Prime[s++];
		}
		else if(n > N)
		{
			n -= Prime[s++];
		}
		else
		{
			if(e >= _MAX)
				break;
			n += Prime[++e];
		}
	}
	printf("%d\n", cnt);
	return 0;
}
