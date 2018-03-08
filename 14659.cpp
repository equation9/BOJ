/*14659번 한조서열정리하고옴ㅋㅋ(C++11)*/
#include <cstdio>
#include <algorithm>
int main()
{
	int Hanzo[30001];
	int N, cnt=0, now, i, max=0;
	scanf("%d", &N);
	for(i = 0; i < N ; i++) scanf("%d", &Hanzo[i]);
	now = Hanzo[0];
	for(i = 1 ; i < N ; i++)
	{
		if(Hanzo[i] < now) cnt++;
		else{
			now = Hanzo[i];
			max = std::max(max, cnt);
			cnt = 0;
		}
	}
	max = std::max(max, cnt);
	printf("%d\n", max);
	return 0;
}
