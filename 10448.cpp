/*10448번 유레카 이론(C++11)*/
#include <cstdio>

int tri(int N, int cnt)
{
	int tmp, fcnt=0;
	if(cnt >= 3)
	{
		return N ? 0 : 1;
	}
	for(int i = 1 ; i < 45 ; i++)
	{
		tmp = i * (i+1) / 2;
		if(N >= tmp)
			fcnt += tri(N-tmp, cnt+1);
		else
			break;
	}
	return fcnt;
}

int main()
{
	int T, num, cnt;
	scanf("%d", &T);
	while(T--)
	{
		cnt = 0;
		scanf("%d", &num);
		printf("%d\n", tri(num, 0) ? 1 : 0);
	}
	return 0;
}
