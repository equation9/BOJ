/*10984번 내 학점을 구해줘(C++11)*/
#include <cstdio>
int main()
{
	int T, i, N, C, sum;
	double score, G;
	scanf("%d", &T);
	while(T--)
	{
		sum = score = 0;
		scanf("%d", &N);
		for(i = 0 ; i < N ; i++)
		{
			scanf("%d %lf", &C, &G);
			sum += C;
			score += C*G;
		}
		printf("%d %.1lf\n", sum, score/sum);
	}
	return 0;
}
