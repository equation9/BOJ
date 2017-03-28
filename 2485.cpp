/*2485번 가로수(C++11)*/
#include <cstdio>
#include <algorithm>

long long int tree[100000], dist[10000], N;

long long int GCD(long long int a, long long int b)
{
	return b ? GCD(b, a%b) : a;
}

int main()
{
	long long int i, cnt = 0, gcd;
	scanf("%lld", &N);
	for(i = 0 ; i < N ; i++)
		scanf("%lld", &tree[i]);
	std::sort(tree, tree+N);
	for(i = 1 ; i < N ; i++)
		dist[i-1] = tree[i] - tree[i-1];
	gcd = dist[0];
	for(i = 1 ; i < N-1 ; i++)
	{
		gcd = GCD(gcd, dist[i]);
	}
	for(i = 0 ; i < N-1 ; i++)
		cnt += dist[i]/gcd -1;
	printf("%lld\n", cnt);
	return 0;
}
