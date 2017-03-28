/*9660번 돌 게임6(C++11)*/
#include <cstdio>
int main()
{
	long long int n;
	bool _flag;
	scanf("%lld", &n);
	n %= 7;
	if(!n || n == 2) _flag = false;
	else _flag = true;
	printf("%s\n", _flag ? "SK" : "CY" );
	return 0;
}
