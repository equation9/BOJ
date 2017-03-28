/*5597번 과제 안 내신 분..?(C++11)*/
#include <cstdio>

int s_num[31];

int main()
{
	int tmp, i;
	for(i = 1 ; i <= 28 ; i++)
	{
		scanf("%d", &tmp);
		s_num[tmp]++;
	}
	for(i = 1 ; i <= 30 ; i++)
	{
		if(!s_num[i])
			printf("%d\n", i);
	}
	return 0;
}
