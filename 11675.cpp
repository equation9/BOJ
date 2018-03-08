/*11675번 Jumbled Communication(C++11)*/
#include <cstdio>

int main()
{
	int N, i;
	int Num[100001];
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
		scanf("%d", &Num[i]);
	for(i = 0 ; i < N ; i++)
	{
		int cmp=0, d = 1, res=0;
		while(d < 256)
		{
			if(Num[i] & d) //다른 값
			{
				//printf("%d\n", Num[i] & d); //디버그
				if(!(cmp&d))
					res += d;
			}
			else //같은 값
			{
				if(cmp & d)
					res += d;
			}
			cmp += 2*(res & d);
			//printf("cmp : %d, res : %d\n", cmp, res); //디버그
			d *= 2;
		}
		printf("%d ", res);
	}
	printf("\n");
	return 0;
}
