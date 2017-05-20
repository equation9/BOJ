/*10709번 기상캐스터(C++11)*/
#include <cstdio>
int main()
{
	char cloud[101][101];
	int H, W, i ,j, k, l;
	scanf("%d %d", &H, &W);
	for(i = 0 ; i < H ; i++) scanf("%s", cloud[i]);

	for(i = 0 ; i < H ; i++)
	{
		for(j = 0 ; j < W ; j++)
		{
			l = -1;
			if(cloud[i][j] == 'c')
				l = 0;
			else
			{
				k = j;
				while(k >= 0 && cloud[i][k] == '.') k--;
				if(cloud[i][k] == 'c') l = j - k;
			}
			printf("%d ", l);
		}
		printf("\n");
	}
	return 0;
}
