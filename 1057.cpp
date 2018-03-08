/*1057번 토너먼트(C++11)*/
#include <cstdio>
int main()
{
	int N, a, b, cnt=1, tmp;
	scanf("%d %d %d", &N, &a, &b);
	if(a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while(1){
		//printf("a : %d  b : %d\n", a, b);//debug
		if((b == a+1) && (a%2))
			return 0 | printf("%d\n", cnt);
	
		a = a/2 + a%2;
		b = b/2 + b%2;
		//N = N/2 + N%2;
		cnt++;
	}
	return 0;
}
