/*3020번 개똥벌레(C++11)*/
#include <cstdio>
#include <algorithm>

int NumM[500001], NumS[500001], Min = 500000;

int main()
{
	int N, H, cnt, mcnt, scnt, i;
	scanf("%d %d", &N, &H);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &cnt);
		switch(i%2)
		{
			case 0 : //짝(석순)
				NumM[cnt-1]++;
				break;
			default : //홀(종유석)
				NumS[H-cnt]++;
				break;
		}
	}
	mcnt = scnt = 0;
	for(i = 0 ; i < H ; i++)
	{
		mcnt += NumM[H-i-1];
		NumM[H-i-1] = mcnt;
		scnt += NumS[i];
		NumS[i] = scnt;
	}
	for(i = 0 ; i < H ; i++)
	{
		//printf("NumM[%d] : %d NumS[%d] : %d\n", i, NumM[i], i, NumS[i]);
		if(NumM[i]+NumS[i] < Min)
		{
			cnt = 1;
			Min = NumM[i]+NumS[i];
		}
		else if(NumM[i]+NumS[i] == Min)
			cnt++;
	}
	printf("%d %d\n", Min, cnt);
	return 0;
}
