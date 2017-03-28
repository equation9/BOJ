/*10250번 ACM 호텔(C++)*/
#include <cstdio>
int main()
{
	int T;
	int H, W, N, res;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &H, &W, &N);
		N--;
		res = ((N % H)+1)*100;
		res += N/H + 1;
		printf("%d\n", res);
	}
	return 0;
}
