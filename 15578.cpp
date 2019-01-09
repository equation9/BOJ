/*15578번 Timovi(C++11)*/
#include <cstdio>

long long int N, M, K;
long long int pat;
long long int dev;
long long int Team[200001];
long long int dir[400001];

int main()
{
	long long int i;
	scanf("%lld %lld %lld", &N, &K, &M);
	pat = 2*N-2;
	dev = M/(pat*K);

	for(i = 0 ; i < pat; i++){
		if(i < N) dir[i] = i;
		else dir[i] = pat-i;
		//printf("%lld\n", dir[i]);//debug
	}
	for(i = 0; i < pat; i++){
		Team[dir[i]] += dev*K; 
	//	printf("team%lld/%lld\n", dir[i], Team[dir[i]]);//debug
	}

	M %= pat*K;
	dev = M/K;
	for(i = 0; i < dev; i++){
		Team[dir[i]] += K;
		//printf("team%d/%d\n", dir[i], Team[dir[i]]);//debug
	}
	Team[dir[i]] += M%K;


	printf("%lld", Team[0]);
	for(i = 1; i < N; i++){
		printf(" %lld", Team[i]);
	}
	printf("\n");
	return 0;
}
