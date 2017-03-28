/*1026번 보물(C++)*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector <int> A, B;
	int N, i, sum=0;
	scanf("%d", &N);
	A.resize(N);
	B.resize(N);
	for(i = 0 ; i < N ; i++)
		scanf("%d", &A[i]);
	for(i = 0 ; i < N ; i++)
		scanf("%d", &B[i]);

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end(), std::greater<int>());
	for(i = 0 ; i < N; i++)
		sum += A[i] * B[i];
	printf("%d\n", sum);
	return 0;
}
