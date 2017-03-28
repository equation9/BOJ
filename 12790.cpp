/*12790번 Mini Fantasy War(C++11)*/
#include <cstdio>
int main()
{
	int i, tmp, T;
	int stat[4];
	scanf("%d", &T);
	while(T--)
	{
		for(i=0 ; i < 4 ; i++)
		{
			scanf("%d", &stat[i]);	
		}
		for(i=0 ; i < 4 ; i++)
		{
			scanf("%d", &tmp);
			stat[i] += tmp;
		}
		stat[0] = stat[0] < 1 ? 1 : stat[0];
		stat[1] = stat[1] < 1 ? 1 : stat[1];
		stat[2] = stat[2] < 0 ? 0 : stat[2];
		printf("%d\n", stat[0] + 5*stat[1] + 2*stat[2] + 2*stat[3]);
	}
	return 0;
}
