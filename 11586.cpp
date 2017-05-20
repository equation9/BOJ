/*11586번 지영 공주님의 마법 거울(C++11)*/
#include <cstdio>
int main()
{
	char face[101][101]; //not the face!
	int N, i, k;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%s", face[i]);
	}
	scanf("%d", &k);
	switch(k)
	{
		case 1 :
			for(i = 0 ; i < N ; i++)
				printf("%s\n", face[i]);
			break;
		case 2 :
			for(i = 0 ; i < N ; i++)
			{
				for(k = N-1 ; k >= 0 ; k--)
					printf("%c", face[i][k]);
				printf("\n");
			}
			break;
		case 3 :
			for(i = N-1 ; i >= 0 ; i--)
				printf("%s\n", face[i]);
			break;
	}
	return 0;
}
