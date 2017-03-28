/*9437번 사라진 페이지 찾기(C++11)*/
#include <cstdio>
#include <algorithm>
int main()
{
	int N, P, Page[3];
	while(1)
	{
		scanf("%d", &N);
		if(!N)
			return 0;
		scanf("%d", &P);
		Page[0] = N+1 - P;
		Page[1] = P%2 ? P+1 : P-1;
		Page[2] = N+1 - Page[1];
		std::sort(Page, Page+3);
		printf("%d %d %d\n", Page[0], Page[1], Page[2]);
	}
	return 0;
}
