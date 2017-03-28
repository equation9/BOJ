/*9095번 1,2,3 더하기(C++11)*/
#include <cstdio>

int dfs(int n)
{
	int cnt=0;
	if(n == 0)
	{
		return 1;
	}
	else if(n < 0)
	{
		return 0;
	}
	cnt += dfs(n-1);
	cnt += dfs(n-2);
	cnt += dfs(n-3);
	return cnt;
}

int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n",dfs(N));
	}
	return 0;
}
