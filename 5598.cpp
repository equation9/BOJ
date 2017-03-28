/*5598번 카이사르 암호(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	int i, len;
	char s[1024];
	scanf("%s", s);
	len = strlen(s);
	for(i = 0 ; i < len ; i++)
	{
		s[i] -= 3;
		if(s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a'))
			s[i] += 26;
	}
	printf("%s\n", s);
	return 0;
}
