/*14656번 조교는 새디스트야!!(C++11)*/
#include <cstdio>
int main()
{
	int i, N, a[20001], cnt=0;
	scanf("%d", &N);
	for(i = 1 ; i <= N ; i++){
		scanf("%d", &a[i]);
		if(a[i] != i) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
