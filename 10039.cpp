/*10039번 평균 점수(C++)*/
#include <cstdio>

int main()
{
	int i, sum=0, tmp;
	for(i = 0 ; i < 5 ; i++)
	{
		scanf("%d", &tmp);
		if(tmp < 40)
			tmp = 40;
		sum += tmp;
	}
	printf("%d\n", sum/5);
	return 0;
}
