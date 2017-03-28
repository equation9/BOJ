/*1292번 쉽게 푸는 문제(C++)*/
#include <cstdio>
int main()
{
	int st, de, cnt=1, i=1, j, sum1=0, sum2 = 0;
	scanf("%d %d", &st, &de);
	while(cnt <= de)
	{
		for(j = 0 ; j < i ; j++)
		{
			if(cnt > de)
				break;
			sum1 += i;
			cnt++;
		}
		i++;
	}
	cnt = i = 1;
	while(cnt <= st-1)
	{
		for(j = 0 ; j < i ; j++)
		{
			if(cnt > st-1)
				break;
			sum2 += i;
			cnt++;
		}
		i++;
	}
	printf("%d\n", sum1 - sum2);

	return 0;
}
