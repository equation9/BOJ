/*2774번 대소문자 바꾸기(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	int i, len;
	char str[101];
	scanf("%s", str);
	len = strlen(str);
	for(i = 0 ; i < len ; i++)
	{
		if(str[i] <= 'Z')
			str[i] += 32;
		else
			str[i] -= 32;
	}
	printf("%s\n", str);
	return 0;
}
