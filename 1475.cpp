/*1475번 방 번호(C++)*/
#include <cstdio>
#include <cstring>

static int Num[10];

int main()
{
	int i, cnt=0;
	char room[1000001];
	scanf("%s", room);
	for(i = 0 ; i < strlen(room) ; i++)
		Num[(int)room[i]-48]++;
	Num[6] += Num[9];
	Num[6] = Num[6]/2 + Num[6]%2;
	for(i = 0 ; i < 9 ; i++)
	{
		while(Num[i] > cnt)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
