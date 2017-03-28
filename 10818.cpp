/*10818번 최소, 최대(C++11)*/
#include <cstdio>
#include <vector>
#include <algorithm>
int main()
{
	std::vector<int> NUM;
	int N,i;
	scanf("%d", &N);
	NUM.resize(N);
	for(i = 0 ; i < N ; i++)
		scanf("%d", &NUM[i]);
	sort(NUM.begin(), NUM.end());
	printf("%d %d\n", NUM[0], NUM[N-1]);
	return 0;
}
