/*2399번 거리의 차이(C++11)*/
#include <cstdio>
#include <algorithm>

long long int arr[10000], N;

int main()
{
	long long int i, j, sum=0;
	scanf("%lld", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%lld", &arr[i]);
	}
	std::sort(arr, arr+N);
	for(i = N-1 ; i > 0 ; i--)
	{
		for(j = 0 ; j < i ; j++)
		{
			sum += arr[i]-arr[j];
		}
	}
	printf("%lld\n", sum*2);
	return 0;
}
