/*2775번 부녀회장이 될테야(C++11)*/
#include <cstdio>

long long int live[15][15];

long long int Howmany(int s, int f)
{
	if(live[s][f])
		return live[s][f];
	else
		return live[s][f] = Howmany(s-1,f) + Howmany(s, f-1);
}

int main()
{
	int T, k, n, i;
	scanf("%d", &T);
	for(i = 1 ; i <= 14 ; i++)
	{
		live[0][i] = i;
		live[i][1] = 1;
	}
	while(T--)
	{
		scanf("%d %d", &k, &n);
		printf("%lld\n", Howmany(k, n));
	}
	return 0;
}
