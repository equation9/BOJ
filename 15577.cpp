/*15577번 Prosjeck(C++11)*/
#include <cstdio>
#include <algorithm>

int N;
double arr[21];
double res;

int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%lf", &arr[i]);
	if(N == 1){
		printf("%lf\n", arr[0]);
		return 0;
	}

	std::sort(arr, arr+N);
	res = (arr[0]+arr[1])/2.0;
	for(i = 2; i < N; i++){
		res = (res+arr[i])/2.0;
	}
	printf("%lf\n", res);
	return 0;
}
