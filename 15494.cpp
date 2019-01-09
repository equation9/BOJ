/*15494번 Davor(C++11)*/
#include <cstdio>

int N, k;

int main()
{
	scanf("%d", &N);
	N /= 364;
	N -= 3;
	k++;
	while(N > 100){
		N -= 3;
		k++;
	}
	printf("%d\n%d\n", N, k);
	return 0;
}
