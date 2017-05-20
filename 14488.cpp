/*14488번 준오는 급식충이야!!(C++11)*/
#include <cstdio>

long double Pos[50001];

int main()
{
	int N, i;
	long double T, s=0, e=0, speed, move;
	scanf("%d %Lf", &N, &T);
	for(i = 0 ; i < N ; i++)
		scanf("%Lf", &Pos[i]);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%Lf", &speed);
		move = speed*T;
		if(i == 0)
		{
			s = Pos[i]-move;
			e = Pos[i]+move;
		}
		else
		{
			if(Pos[i]-move > s) s = Pos[i]-move;
			if(Pos[i]+move < e) e = Pos[i]+move;
	
		}
	}
	printf("%d\n", s <= e ? 1 : 0);
	return 0;
}
