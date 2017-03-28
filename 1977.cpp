/*1977번 완전제곱수(C++11)*/
#include <cstdio>

bool _FLAG;

int main()
{
	int sum=0, i , N, M, n, min=-1;
	scanf("%d %d", &M, &N);
	for(i = 1 ; i <= 100 ; i++)
	{
		n = i*i;
		if(n > N)
		{
			break;
		}
		else if(n >= M && n <= N)
		{
			if(!_FLAG)
			{
				min = n;
				_FLAG = true;
			}
			sum += n;
		}
	}
	if(!_FLAG)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n%d\n", sum, min);
	}
	return 0;
}
