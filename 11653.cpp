/*11653번 소인수분해(C++11)*/
#include <cstdio>

int N;

int main()
{
	int i;
	scanf("%d", &N);
	for(i = 2; i <= N ;)
	{
		if(N%i)
		{
			i++;
			continue;
		}
		N /= i;
		printf("%d\n", i);
	}

	return 0;
}
