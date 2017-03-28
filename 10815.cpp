/*10815번 숫자 카드(C++11)*/
#include <cstdio>
#include <cstring>

int cnt[20000001], M, N;
char OUT[1000002];

int main()
{
	int tmp, i;
	scanf("%d", &N);
	for(i=0 ; i < N ; i++)
	{
		scanf("%d", &tmp);
		cnt[tmp+10000000]++;
	}
	scanf("%d", &M);
	memset(OUT, ' ', (2*M-1)*sizeof(char));
	for(i = 0 ; i < M ; i++)
	{
		scanf("%d", &tmp);
		OUT[i*2] = cnt[tmp+10000000]+'0';
	}
	printf("%s\n", OUT);
	return 0;
}
