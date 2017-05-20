/*14490번 백대열(C++11)*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	char input[25];
	int a, b, len, i;
	scanf("%s", input);
	len = strlen(input);
	a = atoi(input);
	for(i = 0 ; i < len ; i++)
		if(input[i] == ':')
		{
			b = atoi(input + i+1);
			break;
		}
	len = gcd(a, b);
	printf("%d:%d\n", a/len, b/len);
	return 0;
}
