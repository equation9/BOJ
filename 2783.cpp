/*2783번 삼각 김밥(C++11)*/
#include <cstdio>
int main()
{
	int i, N;
	double X, Y, res, tmp;
	scanf("%lf %lf %d", &X, &Y, &N);
	res = (1000/Y)*X;
	for(i = 0 ; i < N ; i++)
	{
		scanf("%lf %lf", &X, &Y);
		tmp = (1000/Y)*X;
		if(res > tmp)
			res = tmp;
	}
	printf("%.2lf\n", res);
	return 0;
}
