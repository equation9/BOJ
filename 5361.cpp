/*5361번 전투 드로이드 가격(C++11)*/
#include <cstdio>
int main()
{
	int T, tmp, i;
	double sum, ar[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
	scanf("%d", &T);
	while(T--)
	{
		sum = 0;
		for(i = 0 ; i < 5 ; i++)
		{
			scanf("%d", &tmp);
			sum += tmp*ar[i];
		}
		printf("$%.2lf\n", sum);
	}
}
