/*1011번 Fly me to the Alpha Centauri(C++)*/
#include <cstdio>

long long int cnt;

void Go(long long int n)
{
	long long int d=n, i=1;
	while(d >= 2*i)
	{
		d -= 2*i;
		//printf("%lld ", i);
		i++;
		cnt += 2;
	}
	if(d >= i)
	{
		d -= i;
		cnt++;
	}
	if(d)
		cnt++;
	return;
}

int main()
{
	long long int T, start, destin;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld", &start, &destin);
		cnt = 0;
		Go(destin - start);
		printf("%lld\n", cnt);
	}
	return 0;
}
