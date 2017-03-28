/*4884번 FIFA 월드컵(C++11)*/
#include <cstdio>
#include <cmath>

long long int Pow_of_two(long long int N)
{
	long long int res=1;
	while(res < N)
	{
		res *= 2;
	}
	return res;
}

int main()
{
	long long int G, A, T, D, x, y;
	long long int go, Max;
	while(1)
	{
		scanf("%lld %lld %lld %lld", &G, &T, &A, &D);
		if(G == -1 && T == -1 && A == -1 && D == -1)
			return 0;
		go = G * A + D;
		Max = Pow_of_two(go);
		//printf("go : %lld Max : %lld\n", go, Max);
		y = Max - go;
		x = G*(T*(T-1))/2 + Max-1;
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n", G, A, T, D, x, y);
	}
	return 0;
}
