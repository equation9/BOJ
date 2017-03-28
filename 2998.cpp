/*2998번 8진수(C++11)*/
#include <cstdio>
#include <cstring>

char binary[103];

int main()
{
	char str[101];
	int i=0, len, res;
	scanf("%s", str);
	len = strlen(str);
	while(len%3)
	{
		binary[i++] = '0';
		len++;
	}
	strncat(binary, str, 101);
	for(i = 0 ; i < len ;)
	{
		res = 0;
		if(binary[i++] == '1')
			res += 4;
		if(binary[i++] == '1')
			res += 2;
		if(binary[i++] == '1')
			res += 1;
		printf("%d", res);
	}
	printf("\n");
	return 0;
}
