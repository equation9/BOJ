/*8896번 가위 바위 보(C++11)*/
#include <cstdio>
#include <cstring>

char Robot[10][31];
int Survived[10], T, N, k;

int RSP(int dig)
{
	int i, surv,cnt =0, rcp_cnt[3];
	char loose;
	if(dig > k)
		return 0;
	for(i = 0 ; i < N ; i++)
	{
		if(Survived[i])
		{
			surv = i+1;
			cnt++;
		}
	}
	if(cnt == 1)
		return surv;

	//주먹 가위 보
	memset(rcp_cnt, 0, 3*sizeof(int));
	for(i = 0 ; i < N ; i++)
	{
		if(!Survived[i])
			continue;

		if(Robot[i][dig] == 'R')
			rcp_cnt[0] = 1;
		else if(Robot[i][dig] == 'S')
			rcp_cnt[1] = 1;
		else
			rcp_cnt[2] = 1;
	}
	cnt = rcp_cnt[0] + rcp_cnt[1] + rcp_cnt[2];
	
	if(cnt == 2)
	{
		if(rcp_cnt[0] && rcp_cnt[1])
		{
			loose = 'S';
		}
		else if(rcp_cnt[0] && rcp_cnt[2])
		{
			loose = 'R';
		}
		else
		{
			loose = 'P';
		}

		for(i = 0 ; i < N ; i++)
		{
			if(!Survived[i])
				continue;
			
			if(Robot[i][dig] == loose)
				Survived[i] = 0;
		}
	}
	return RSP(dig+1);
}

int main()
{
	int i;
	scanf("%d", &T);
	while(T--)
	{
		memset(Survived, 1, 10*(sizeof(int)));
		scanf("%d", &N);
		for(i = 0 ; i < N ; i++)
			scanf("%s", Robot[i]);
		k = strlen(Robot[0]);
		printf("%d\n", RSP(0));
	}
	return 0;
}
