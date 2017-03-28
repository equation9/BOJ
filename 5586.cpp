/*5586번 JOI와 IOI(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	int J, I, i, len;
	char str[10001];
	scanf("%s", str);
	J = I = 0;
	len = strlen(str);
	for(i = 0 ; i < len ; i++)
	{
		if(str[i] == 'J')
		{
			if(!strncmp(str+i, "JOI", 3))
				J++;
		}
		else if(str[i] == 'I')
		{
			if(!strncmp(str+i, "IOI", 3))
				I++;
		}
	}
	printf("%d\n%d\n", J, I);
	return 0;
}
