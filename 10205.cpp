/*10205번 헤라클레스와 히드라(C++11)*/
#include <cstdio>
#include <cstring>

int main()
{
	int T, N, len, i, Loop;
	char Act[101];
	scanf("%d", &T);
	for(Loop = 1 ; Loop <= T ; Loop++)
	{
		scanf("%d %s", &N, Act);
		len = strlen(Act);
		for(i = 0 ; i < len ; i++)
		{
			if(Act[i] == 'b') 
			{
				N--;
				if(!N)
					break;
			}
			else N++;
		}
		printf("Data Set %d:\n%d\n\n", Loop, N);
	}
	return 0;
}
