/*13458번 시험 감독(C++11)*/
#include <cstdio>
int main()
{
	long long int N, i, room[1000001], b, c;
	scanf("%lld",&N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%lld", &room[i]);
	}
	scanf("%lld %lld", &b, &c);
	long long int cnt =N;
	for(i = 0 ; i < N ; i++)
	{
		room[i] -= b;
		if(room[i]>0) cnt += (room[i])/c;
		if((room[i])%c > 0) cnt++;
	}
	printf("%lld\n", cnt);
	return 0;
}
