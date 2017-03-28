/*2490번 윷놀이(C++11)*/
#include <cstdio>
int main()
{
	int i,j, cnt, tmp;
	for(i = 0 ; i < 3 ; i++)
	{
		cnt = 0;
		for(j = 0 ; j < 4 ; j++)
		{
			scanf("%d", &tmp);
			cnt += tmp;
		}
		switch(cnt)
		{
			case 0 :
				printf("D\n");
				break;
			case 4 :
				printf("E\n");
				break;
			case 2 :
				printf("B\n");
				break;
			case 3 :
				printf("A\n");
				break;
			case 1 :
				printf("C\n");
				break;
		}
	}
	return 0;
}
