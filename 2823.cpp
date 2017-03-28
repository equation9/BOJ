/*2823번 유턴 싫어(C++11)*/
#include <cstdio>

int main()
{
	char Road[10][11];
	int i, j, cnt, R, C;
	scanf("%d %d", &R, &C);
	for(i = 0 ; i < R ; i++)
		scanf("%s", Road[i]);
	for(i = 0 ; i < R ; i++)
	{
		for(j = 0 ; j < C ; j++)
		{
			cnt = 0;
			if(Road[i][j] == '.')
			{
				if(i -1 >= 0 && Road[i-1][j] =='.')
					cnt++;
				if(i + 1 < R && Road[i+1][j] =='.')
					cnt++;
				if(j - 1 >= 0 && Road[i][j-1] =='.')
					cnt++;
				if(j + 1 < C && Road[i][j]+1 =='.')
					cnt++;
				if(cnt <= 1)
				{
					printf("1\n");
					return 0;
				}
			}
		}
	}
	printf("0\n");
	return 0;
}
