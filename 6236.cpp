/*6236번 용돈 관리(C++11)*/
#include <cstdio>
#include <algorithm>

int N, M, max;
int money[100001];

int main()
{
	int i;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i< N ; i++){
		scanf("%d", &money[i]);
		max = std::max(max, money[i]);
	}
	//if(N==M) return 0 | printf("%d\n", max);

	int s= max-1, e= 1000000000; //10000*100000
	while(s+1 < e)
	{
		int mid = (s+e)/2;
		int sum = 0, cnt = 1;
		if(mid < max)
		{
			s = mid;
			continue;
		}

		for(i = 0 ; i < N ; i++)
		{
			sum += money[i];
			if(sum > mid)
			{
				cnt++;
				sum = money[i];
			}
		}

		if(cnt <= M) e = mid;
		else s = mid;
	}
	return 0 | printf("%d\n", e);
}
