/*5046번 전국 대학생 프로그래밍 대회 동아리 연합(C++11)*/
#include <cstdio>

int main()
{
	int i, j;
	int N, B, H, W, hp, ha, sum, min;
	scanf("%d %d %d %d", &N, &B, &H, &W);
	min = B+100;
	for(i = 0 ; i < H ; i++)
	{
		sum = B+200;
		scanf("%d", &hp);
		for(j = 0 ; j < W ; j++)
		{
			scanf("%d", &ha);
			if(ha >= N)
				sum = hp*N;
		}
		if(sum < min)
			min = sum;
	}
	if(min <= B)
		printf("%d\n", min);
	else
		printf("stay home\n");
	return 0;
}
