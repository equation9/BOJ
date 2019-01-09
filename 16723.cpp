/*16723번 원영이는 ZOAC과 영원하고 싶다(C++11)*/
/*최대 2^29*/
#include<cstdio>

long long int square[30];
long long int dp(int n){
	if(square[n]) return square[n];
	square[n] = dp(n-1)*2+(1<<(n-1));
	//printf("[%d]%lld\n", n, square[n]);//debug
	return square[n];
}

int main()
{
	long long int n;
	long long int res;
	long long int i, ntmp, tmp;

	scanf("%lld", &n);
	res =0;

	square[0] = 1;
	square[1] = 3;
	dp(29);

	while(n>0){
		ntmp=1;
		tmp = 0;
		while(n >= ntmp){
			ntmp *= 2;
			tmp++;
		}
		tmp--;
		ntmp/=2;
		res += square[tmp];
		//	printf("2^%d= %d\n", tmp, 1<<tmp);//debug
		n -= ntmp;
	}
	printf("%lld\n", res*2);

	return 0;
}
