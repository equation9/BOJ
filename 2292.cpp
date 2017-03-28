/*2292번 벌집(C++)*/
#include <cstdio>
int main(){
	long long int Num;
	long long int i=0, cnt=1, sum=1;
	scanf("%lld", &Num);
	while(sum < Num)
	{
		sum += (cnt)*6;
		cnt++;
	}

	printf("%lld\n", cnt);
	return 0;
}
