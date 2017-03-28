/*11720번 숫자의 합(C++)*/
#include <cstdio>
int main(){
	int N, i, sum=0;
	scanf("%d", &N);
	char num[N+1];
	scanf("%s", num);
	for(i = 0 ; i < N ; i++)
		sum += (int)num[i]-48;
	printf("%d\n", sum);
	return 0;
}
