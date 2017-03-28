/*13300번 방 배정(C++11)*/
#include <cstdio>

int stud[7][2], N, K;

int main()
{
	int i, j, s, y;
	scanf("%d %d", &N, &K);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d %d", &s, &y);
		stud[y][s]++;
	}
	s = 0;
	for(i = 1 ; i <= 6 ; i++)
	{
		for(j = 0 ; j < 2; j++)
		{
			s += stud[i][j]/K;
			if(stud[i][j]%K)
				s++;
		}
	}
	printf("%d\n", s);
	return 0;
}
