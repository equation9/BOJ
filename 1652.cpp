/*1652번 누울 자리를 찾아라(C++11)*/
#include <cstdio>

char Room[100][101];
int N;

int Row_cnt(int L)
{
	int i, cnt = 0;
	for(i = 0 ; i < N ; i++)
	{
		if(Room[L][i] == '.')
		{
			if(i < N-1 && Room[L][i+1] == '.')
			{
				cnt++;
				while(Room[L][i] == '.')
					i++;
			}
		}
	}
	return cnt;
}

int Column_cnt(int L)
{
	int i, cnt = 0;
	for(i = 0 ; i < N ; i++)
	{
		if(Room[i][L] == '.')
		{
			if(i < N-1 && Room[i+1][L] == '.')
			{
				cnt++;
				while(Room[i][L] == '.')
					i++;
				i--;
			}
		}
	}
	return cnt;
}

int main()
{
	int i, rcnt=0, ccnt=0;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
		scanf("%s", Room[i]);
	for(i = 0 ; i < N ; i++)
	{
		rcnt += Row_cnt(i);
		ccnt += Column_cnt(i);
	}
	printf("%d %d\n", rcnt, ccnt);
	return 0;
}
