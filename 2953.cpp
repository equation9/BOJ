/*2953번 나는 요리사다(C++11)*/
#include <cstdio>
int main()
{
	int i, j, winner=0, wins=0, sum, tmp;
	for(i = 1 ; i <= 5 ; i++)
	{
		sum = 0;
		for(j = 0 ; j < 4 ; j++)
		{
			scanf("%d", &tmp);
			sum += tmp;
		}
		if(sum > wins)
		{
			winner = i;
			wins = sum;
		}
	}
	printf("%d %d\n", winner, wins);
	return 0;
}
