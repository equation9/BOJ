/*2622번 삼각형만들기(C++11)*/
#include <cstdio>
int main()
{
	int N, i, tmp=0, cnt=0;
	scanf("%d", &N);
	if(N%3)
		tmp = 1;
	for(i = 1 ; i <= N/3; i++)
	{
		cnt += (N-i)/2;
		printf("%d %d\n", i, cnt);
	}
	printf("%d\n", cnt);
	return 0;
}
