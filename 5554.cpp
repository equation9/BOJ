/*5554번 심부름 가는 길(C++11)*/
#include <cstdio>
int main()
{
	int i, y, sum=0;
	for(i = 0 ; i < 4 ; i++)
	{
		scanf("%d", &y);
		sum += y;
	}
	printf("%d\n%d\n", sum/60, sum%60);
	return 0;
}
