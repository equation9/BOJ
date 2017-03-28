/*1222번 홍준 프로그래밍 대회(C++11)*/
#include <cstdio>
#include <cmath>
#include <algorithm>

long long int School[2000001], N, Max;

int main()
{
	long long int i, j, res=0, tmp;
	scanf("%lld", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%lld", &tmp);
		School[tmp]++;
		//printf("%lld, %lld\n", tmp, School[tmp]);
		Max = std::max(tmp, Max);
	}
	for(i = 1 ; i <= Max ; i++)
	{
		tmp = 0;
		for(j = i ; j <= Max ; j += i)
		{
			tmp += School[j];
		}
		if(tmp > 1)
			res = std::max(res, tmp*i);
	}
	printf("%lld\n", res);
	return 0;
}
