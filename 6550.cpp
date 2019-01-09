/*6550번 부분 문자열(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	char a[100001], b[100000];
	int i, j;
	int alen, blen;
	bool _flag;
	while(scanf("%s", a) > 0){
		scanf("%s", b);
		
		i = j = 0;
		_flag = false;

		while(a[i]!=0x00 && b[j]!=0x00){
			if(b[j] == a[i]){
				//printf("-%c\n", a[i]);//debug
				i++;
			}
			j++;
		}
		if(a[i] == 0x00) _flag = true;
		printf("%s\n", _flag ? "Yes" : "No");
	}
	return 0;
}
