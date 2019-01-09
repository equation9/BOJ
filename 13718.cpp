/*13718번 Tavan(C++11)*/
#include <cstdio>
#include <algorithm>

int N, M, K, X;
char str[501];
char pos[501][27];

int main()
{
	int i, j;
	scanf("%d %d %d %d", &N, &M, &K, &X);
	scanf("%s", str);

	for(i = 0 ; i < M; i++){
		scanf("%s", pos[i]);
		std::sort(pos[i], pos[i]+K);
	}

	j = M-1;
	X--;
	for(i = N-1; i >= 0; i-- ){
		if(str[i] != '#') continue;

		str[i] = pos[j][X%K];
		j--;
		X /= K;
	}
	printf("%s\n", str);
	return 0;
}
