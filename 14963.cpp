/*14963번 Cezar(C++11)*/
#include <cstdio>

int card[12];
int N, X, cnt1, cnt2;

int main()
{
	int i;
	for(i = 2; i <= 11; i++)
		card[i] = 4;
	card[10] = 16;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		int a;
		scanf("%d", &a);
		X += a;
		card[a]--;
	//	printf("card[%d]=%d\n", a, card[a]);//debug
	}
	if(X >= 20){
		printf("DOSTA\n");
		return 0;
	}

	X = 21-X;
	if(X >= 11){
		printf("VUCI\n");
		return 0;
	}

	for(i = 2; i <= X; i++)
		cnt1 += card[i];
	for(i = X+1; i <= 11; i++)
		cnt2 += card[i];
	//printf("cnt1=%d cnt2=%d\n", cnt1, cnt2);//debug
	printf("%s\n", cnt2 >= cnt1 ? "DOSTA":"VUCI" );
	return 0;
}
