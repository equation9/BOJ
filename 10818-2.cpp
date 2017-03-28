/*10818번 최소, 최대(C++11)*/
#include <cstdio>
int main()
{
	int N, i, tmp,  min=1000000, MAX=-1000000;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &tmp);
		if(tmp < min)
			min = tmp;
		if(tmp > MAX)
			MAX = tmp;
	}
	printf("%d %d\n", min, MAX);
	return 0;
}
