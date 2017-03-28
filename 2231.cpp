/*2231번 분해합(C++11)*/
#include <cstdio>
#include <cmath>
int main()
{
	int N, res = 0, sum, po, tmp, i, j;
	scanf("%d", &N);
	for(i = 1 ; i < N ; i++)
	{
		sum = tmp = i;
		for(j = 6 ; j >= 0 ; j--)
		{
			po = (int)pow(10.0, (double)j);
			sum += tmp / po;
			tmp %= po;
		}
		if(sum == N)
		{
			res = i;
			break;
		}
	}
	printf("%d\n", res);
	return 0;
}
