/*5637번 가장 긴 단어(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	char C, Str[101], Res[101] = "", Max=0, len;
	int i=0;
	while(C = getchar())
	{
		if(C == '-' || (C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z'))
		{
			Str[i++] = C;
		}
		else
		{
			Str[i] = '\0';
			//printf("===\n%s\n===\n", Str);//디버그
			
			if(!strcmp(Str, "E-N-D")) break;
			
			len = i;
			if(Max < len)
			{
				Max = len;
				strcpy(Res, Str);
				for(i = 0 ; i < len ; i++)
				{
					if(Res[i] >= 'A' && Res[i] <= 'Z')
					{
						Res[i] += 'a' - 'A';
					}
				}
			}
			i = 0;
		}
	}
	printf("%s\n", Res);
	return 0;
}
