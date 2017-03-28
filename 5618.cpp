/*5618번 공약수(C++11)*/
#include <cstdio>

int Num[3], N;

int get_mini()
{
	int smaller = Num[0];
	for(int i=1 ; i < N ;i++)
	{
		if(smaller > Num[i])
			smaller = Num[i];
	}
	return smaller;
}

int main()
{
	int i, j, N, min, cnt;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &Num[i]);
	}
	min = get_mini();
	for(i = 1 ; i <= min ; i++)
	{
		cnt = 0;
		for(j = 0 ; j < N ; j++)
		{
			cnt += (Num[j] % i);
		}
		if(!cnt)
			printf("%d\n", i);
	}
	return 0;
}
