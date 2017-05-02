/*1159번 농구 경기(C++11)*/
#include <cstdio>

int cnt[26];

int main()
{
	bool _flag = true;
	int i, n;
	char str[151];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", str);
		cnt[str[0]-'a']++;
	}

	for(i = 0 ; i < 26 ; i++)
	{
		if(cnt[i] >= 5)
		{
			printf("%c", i+'a');
			_flag = false;
		}
	}
	if(_flag) printf("PREDAJA\n");
	else printf("\n");
	return 0;
}
