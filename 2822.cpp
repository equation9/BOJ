/*2822번 점수 계산(C++11)*/
#include <cstdio>
#include <algorithm>
#define N 8
#define M 5

struct PROB{
	int num;
	int score;
	bool operator<(const PROB &b)
	{
		return this->score > b.score;
	}
};

PROB p[N];
int NOP[M];

int main()
{
	int i, sum=0;
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &p[i].score);
		p[i].num = i+1;
	}
	std::sort(p, p+N);
	for(i = 0 ; i < M ; i++)
	{
		sum += p[i].score;
		NOP[i] = p[i].num;
	}
	std::sort(NOP, NOP+M);
	printf("%d\n", sum);
	for(i = 0 ; i < M ; i++)
		printf("%d ", NOP[i]);
	printf("\n");
	return 0;
}
