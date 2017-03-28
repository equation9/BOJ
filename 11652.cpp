/*11652번 카드(C++11)*/
#include <cstdio>
#include <algorithm>

long long int Arr[1000000];

int main()
{
	long long int N, loop, i=0, cnt,res=0, res_n;
	scanf("%lld", &N);
	for(loop = 0 ; loop < N ; loop++)
	{
		scanf("%lld", &Arr[loop]);
	}
	std::sort(Arr, Arr+N);
	res_n = Arr[0];
	while(i < N)
	{
		loop = Arr[i];
		cnt = 0;
		if(i < N-1 && Arr[i+1] == loop)
		{
			while(i < N && Arr[i] == loop)
			{
				cnt++;
				i++;
				//printf("%lld\n", loop);
			}
			i--;
		}
		if(cnt > res)
		{
			res = cnt;
			res_n = loop;
			//printf("%lld: %lld\n", loop, cnt);
		}
		i++;
	}
	printf("%lld\n", res_n);
	return 0;
}
