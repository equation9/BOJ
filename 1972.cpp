/*1972번 놀라운 문자열(C++11)*/
#include <cstdio>
#include <cstring>

bool alph[677];
bool _flag;
char str[100];
int len;

int main()
{
	int i, j;
	while(1)
	{
		scanf("%s", str);
		if(!strcmp(str, "*")) break;

		len = strlen(str);
		_flag = true;
		for(j = 1; j < len-1 ; j++){
			memset(alph, false, sizeof(alph));
			for(i = 0; i+j < len; i++){
				//printf("%c%c\n", str[i], str[i+j]);//debug
				int num = (str[i]-'A')*26 + (str[i+j]-'A');
				if(alph[num]) _flag = false;
				alph[num] = true;
			}
		}
		printf("%s is%ssurprising.\n", str, _flag? " " : " NOT ");
	}
	return 0;
}
