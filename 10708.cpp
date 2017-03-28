/*10708번 クリスマスパーティー(C++11)*/
#include <cstdio>

int N, M, Tomo[101], Target[101];

int main()
{
	int i, j, tmp, cnt;
	scanf("%d %d", &N, &M);
	for(i = 1 ; i <= M ; i++)
		scanf("%d", &Target[i]);
	for(i = 1 ; i <= M ; i++)
	{
		cnt = 0;
		for(j = 1 ; j <= N ; j++)
		{
			scanf("%d", &tmp);
			if(tmp == Target[i])
				Tomo[j] += 1;
			else
				cnt++;
		}
		Tomo[Target[i]] += cnt;
	}
	for(i = 1 ; i <= N ; i++)
		printf("%d\n", Tomo[i]);
	return 0;
}
