/*1316번 그룹 단어 체커(C++)*/
#include <cstdio>
#include <cstring>

int alp_cnt[26];

int main()
{
	int N, cnt=0, len, i, j;
	char str[101];
	scanf("%d", &N);
	while(N--)
	{	
		for(i = 0 ; i < 26 ; i++)
			alp_cnt[i] = 0;
		scanf("%s", str);
		len = strlen(str);
		for(i = 0 ; i < len ; i++)
			alp_cnt[(int)str[i]-97]++;

		for(i = 0 ; i < len ; i)
		{
			j = 0;
			while(str[i+j] == str[i]) 
			{
				j++;
			}
			if(alp_cnt[(int)str[i]-97] != j)
			{
				break;
			}
			i += j;
			if(i == len)
				cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
