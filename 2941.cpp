/*2941번 크로아티아 알파벳(C++)*/
#include <cstdio>
#include <cstring>

#define CHECK_BUG(x) printf("%c", x);

int main()
{
	int cnt = 0, i=0;
	char str[101];
	scanf("%s", str);
	while(i < strlen(str))
	{
		switch(str[i])
		{
			case 'c' :
				if(str[i+1] == '=' || str[i+1] == '-')
					i += 2;
				else
					i++;
				cnt++;
				break;
			case 'd' :
				if(str[i+1] == '-')
					i += 2;
				else if(str[i+1] == 'z' && str[i+2] == '=')
					i += 3;
				else
					i++;
				cnt++;
				break;
			case 'l' :
			case 'n' :
				if(str[i+1] == 'j')
					i += 2;
				else
					i++;
				cnt++;
				break;
			case 's' :
			case 'z' :
				if(str[i+1] == '=')
					i += 2;
				else
					i++;
				cnt++;
				break;
			default :
				i++;
				cnt++;
				break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
