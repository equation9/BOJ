/*3034번 앵그리 창영(C++11)*/
#include <cstdio>
#include <cmath>
int main()
{
	int N;
	double W, H, tmp, Diago;
	scanf("%d %lf %lf", &N, &H, &W);
	Diago = sqrt(pow(H, 2.0)+pow(W, 2.0));
	while(N--)
	{
		scanf("%lf", &tmp);
		printf("%s\n", tmp <= Diago ? "DA" : "NE");
	}
	return 0;
}
