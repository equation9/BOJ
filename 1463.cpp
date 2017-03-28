/*1463번 1로 만들기(C++)*/
/*백트래킹*/
#include <cstdio>
int N;
static int res;

void Make_one(int n, int cnt)
{
	if (n <= 1)
	{
		if((res && (cnt < res)) || !res)
			res = cnt;
		return;
	}
	if(res && cnt >= res)
		return;

	if(!(n%3))
	{
		Make_one(n/3, cnt+1);
	}
	if(!(n%2))
	{
		Make_one(n/2, cnt+1);
	}

	Make_one(n-1, cnt+1);
	
	return;
}

int main()
{
	scanf("%d", &N);
	Make_one(N, 0);
	printf("%d\n", res);
	return 0;
}
