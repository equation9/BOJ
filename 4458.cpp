/*4458번 첫 글자를 대문자로(C++11)*/
#include <cstdio>
#include <cstdlib>
int main()
{
	char str[1024];
	int T;
	fgets(str, 1024, stdin);
	T= atoi(str);
	while(T--)
	{
		fgets(str, 1024, stdin);
		if(str[0] >= 'a')
			str[0] = str[0] - 'a' + 'A';
		printf("%s", str);
	}
	return 0;
}
