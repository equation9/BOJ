/*2877번 4와 7(C++11)*/
#include <cstdio>
#include <cmath>

int K, L, Num[31];

int main()
{
	int i, tmp, cnt=0;
	scanf("%d", &K);
	L = (int)log2(K+2l); //자릿수n -> 2*(2^n -1)
	tmp = (int)pow(2.0, L) - 2;
	
	if(tmp == K)
	{
		L--;
		for(i = 0 ; i < L ; i++)
			Num[i] = 7;
	}
	else
	{
		for(i = 0 ; i < L ; i++)
			Num[i] = 4;
		tmp = K - tmp-1;
		i = 1;
		//printf("K:%d L:%d tmp:%d\n", K, L, tmp);
		while(i <= tmp)
		{
			//printf("%d\n", i|tmp);
			if(i & tmp)
				Num[cnt] = 7;
			i = i<<1;
			cnt++;
		}
	}

	for(i = L-1 ; i >= 0 ; i--)
		printf("%d", Num[i]);
	printf("\n");
	return 0;
}
