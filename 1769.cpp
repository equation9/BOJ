/*1769번 3의 배수(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	char Num[1000001];
	long long int cnt=0, num=10, i, len;
	scanf("%s", Num);
	if(strlen(Num) < 2)
	{
		printf("0\n%s\n", !((Num[0]-'0')%3) ? "YES" : "NO");
		return 0;
	}
	while(num >= 10)
	{
		num = 0;
		len = strlen(Num);
		for(i = 0 ; i < len ; i++)
		{
			num += (long long int)Num[i]-'0';
		}
		cnt++;
		snprintf(Num, 1000001, "%lld", num);
	}
	printf("%lld\n%s\n", cnt, num%3 ? "NO" : "YES");
	return 0;
}
