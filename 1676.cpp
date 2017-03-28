/*1676번 팩토리얼 0의 개수(C++11)*/
#include <cstdio>
int main()
{
	int N, cnt=0, i, tmp;
	scanf("%d", &N);
	for(i = 1 ; i <= N ; i++)
	{
		tmp = i;
		while(!(tmp%5))
		{
			cnt++;
			tmp /= 5;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
