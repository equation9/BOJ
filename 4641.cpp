/*4641번 Doubles(C++11)*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

int main()
{
	char s[60];
	int N, i, j, num[16], len, cnt;
	while(1)
	{
		fgets(s, 60, stdin);
		if(!strncmp(s, "-1", 2))
			return 0;
		len = strlen(s);
		j = cnt = 0;
		for(i = 0 ; i < len-1 ; i++)
		{
			if(s[i] != ' ')
			{
				num[j++] = atoi(s+i);
				while(s[i] >= '0' && s[i] <= '9') i++;
			}
		}
		N = j;
		std::sort(num, num+N);
		for(i = 0 ; i < N ; i++)
		{
			for(j = i+1 ; j < N ; j++)
				if(num[i]*2 == num[j]) cnt++;
		}
		printf("%d\n", cnt);
	}
}
