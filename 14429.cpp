/*14429번 배스킨라빈스 31(C++11)*/
#include <cstdio>
int main()
{
	int n, j, m;
	int i;
	int min=87654321, mnum=0;
	scanf("%d", &n);
	for(i = 1 ; i <= n ; i++)
	{
		int turn;
		scanf("%d %d", &j, &m);
		turn = 2*((j-1)/(m+1))+2;
		if(turn < min)
		{
			min = turn;
			mnum = i;
		}
	}
	printf("%d %d\n", mnum, min);
	return 0;
}
