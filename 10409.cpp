/*10409번 서버(C++11)*/
#include <cstdio>

int time[50];

int main()
{
	int n, T, i, sum=0;
	scanf("%d %d", &n, &T);
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d", &time[i]);
	}
	for(i = 0 ; i < n ; i++)
	{
		sum += time[i];
		if(sum > T)
		{
			break;
		}
	}
	printf("%d\n", i);
	return 0;
}
