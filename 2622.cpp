/*2622번 삼각형만들기(C++11)*/
#include <cstdio>
int main()
{
	int N, i, j, k, cnt=0;
	scanf("%d", &N);
	for(i = 1 ; i <= N/3 ; i++)
	{
		for(j = i ; j <= (N-i)/2 ; j++)
		{
			k = N-i-j;
			if(i+j > k)
			{
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
