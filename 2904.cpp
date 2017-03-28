/*2904번 수학은 너무 쉬워(C++11)*/
#include <cstdio>

int N, num[100][2];

int IntPow(int n, int r)
{
	int res=1, i;
	for(i = 1 ; i <= r ; i++)
		res *= n;
	return res;
}

int main()
{
	int res=1, i, j, cnt=0, cnttmp, dec_cnt=0;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &num[i][0]);
	}
	for(i = 2 ; i <= 1000000 ; i)
	{
		cnttmp = 0;//소수로 나눠지는지 확인용
		for(j = 0 ; j < N ; j++)
		{
			if(!(num[j][0] % i))
			{
				num[j][0] /= i;
				num[j][1]++;
				dec_cnt++;
				cnttmp ++;
			}
		}
		if(!cnttmp)
		{
			dec_cnt /= N;
			for(j = 0 ; j < N ; j++)
			{
				if(num[j][1] < dec_cnt)
					cnt += dec_cnt - num[j][1];
				num[j][1] = 0;
			}
			res *= IntPow(i, dec_cnt);
			dec_cnt = 0;
			i++;
		}
	}
	printf("%d %d\n", res, cnt);
	return 0;
}
