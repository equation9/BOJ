/*11024번 더하기 4(C++11)*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
int main()
{
	char Num[4096];
	int i, len, T, sum;
	scanf("%d", &T);
	fgets(Num, 4096, stdin);
	while(T--)
	{
		fgets(Num, 4096, stdin);
		len = strlen(Num);
		sum = 0;
		for(i = 0 ; i < len ; i++)
		{
			if(Num[i] >= '0' && Num[i] <= '9')
			{
				sum += atoi(Num+i);
				while(Num[i] >= '0' && Num[i] <= '9')
				{
					i++;
				}
				i--;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
