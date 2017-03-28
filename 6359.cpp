/*6369번 만취한 상범(C++11)*/
#include <cstdio>
#include <cstring>
#include <algorithm>
int N, room[101];
int main()
{
	int T, i, j, cnt;
	scanf("%d", &T);
	while(T--)
	{
		std::fill(room, room+101, 1);
		scanf("%d", &N);
		cnt=0;
		for(i = 2 ; i <= N ; i++)
		{
			for(j = 1 ; j <= N/i ; j++)
			{
				if(room[j*i])
					room[j*i] = 0;
				else
					room[j*i] = 1;
			}
		}
		for(i = 1 ; i<= N ; i++)
			cnt += room[i];
		printf("%d\n", cnt);
	}

	return 0;
}
