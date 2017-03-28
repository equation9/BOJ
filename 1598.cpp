/*1598번 꼬리 무는 숫자 나열(C++11)*/
#include <cstdio>
int main()
{
	int N, M, sum=0, tmp, Nmod, Mmod;
	scanf("%d %d", &N, &M);
	if(N < M)
	{
		tmp = N;
		N = M;
		M = tmp;
	}
	Nmod= N%4;
	if(!(N%4))
		Nmod = 4;
	Mmod= M%4;
	if(!(M%4))
		Mmod = 4;
	
	sum += (N-Nmod - (M-Mmod))/4;
	tmp = Nmod - Mmod;
	if(tmp < 0)
		tmp = -tmp;
	sum += tmp;
	printf("%d\n", sum);
	return 0;
}
