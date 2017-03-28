/*5032번 탄산 음료(C++11)*/
#include <cstdio>

int bott, N;

int main()
{
	int tmp, cnt;
	scanf("%d %d %d", &bott, &tmp, &N);
	bott += tmp;
	cnt = 0;
	while((bott / N))
	{
		tmp = bott/N;
		bott %= N;
		bott += tmp;
		cnt += tmp;
	}
	printf("%d\n", cnt);
	return 0;
}
