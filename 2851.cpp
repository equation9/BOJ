/*2851번 슈퍼 마리오(C++11)*/
#include <cstdio>
int main()
{
	int i,tmp, sum=0, mush[10];
	for(i = 0 ; i < 10 ; i++)
	{
		scanf("%d", &mush[i]);
	}
	for(i = 0 ; i < 10 ; i++)
	{
		sum += mush[i];
		if(sum > 100)
		{
			if((sum - 100) > (100 - sum + mush[i]))
				sum -= mush[i];
			break;
		}
		else if(sum == 100)
			break;
	}
	printf("%d\n", sum);
	return 0;
}
