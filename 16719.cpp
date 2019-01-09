/*16719번 ZOAC(C++11)*/
#include <cstdio>
#include <cstring>

char s[101];
int check[101];
int len, cnt;

int main()
{
	int i;
	int minn, start;
	char minc;

	scanf("%s", s);
	len = strlen(s);
	while(cnt != len)
	{
		start = len-1;
		minn = -1;
		while(minn == -1){
			if(start < 0) return 0;
			while(start >= 0 && !check[start]) start--;
			for(i = start+1; i < len && !check[i]; i++){
				if(minn == -1 || s[i] < minc){
					minn = i;
					minc = s[i];
				}
			}
			start--;
		}
		//printf("min %c\n", minc);//debug
		check[minn] = 1;
		cnt++;
		minn = -1;

		for(i = 0; i < len; i++){
			if(check[i])
				printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}
