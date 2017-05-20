/*14487번 욱제는 효도쟁이야!!(C++11)*/
#include <cstdio>
int main()
{
	int sum = 0, max = 0, N, i, a;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &a);
		sum += a;
		if(a > max) max = a;
	}
	printf("%d\n", sum - max);
	return 0;
}
