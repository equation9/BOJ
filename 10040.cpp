/*10040번 투표(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	int N, M, Game[1001], i, Vote[1001], tmp, max = 0;
	memset(Vote, 0, sizeof(Vote));
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < N ; i++) scanf("%d", &Game[i]);
	while(M--)
	{
		scanf("%d", &tmp);
		for(i = 0 ; i < N ; i++)
		{
			if(Game[i] <= tmp)
			{
				Vote[i]++;
				break;
			}
		}
	}
	for(i = 0 ; i < N ; i++)
	{
		if(Vote[i] > Vote[max]) max = i;
	}
	printf("%d\n", max+1);
	return 0;
}
