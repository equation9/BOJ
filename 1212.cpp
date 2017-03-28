/*1212번 8진수 2진수*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define BUG_TEST(x)  printf("%d\n", x);

int main()
{
	int i, div, num, cnt, len;
	char octal[333335], binary[1333347];
	scanf("%s", octal);
	if(atoi(octal) == 0)
	{
		printf("0\n");
		return 0;
	}

	len = strlen(octal);
	div = 4;
	cnt = 0;
	num = (int)octal[0] - 48;
	while(div)
	{
		if(num / div)
		{
			binary[cnt++] = '1';
			num -= div;
		}
		else
		{
			if(cnt)
			{
				binary[cnt++] = '0';
			}
		}
		div /= 2;
	}
	binary[cnt] = '\0';

	for(i = 1 ; i < len ; i++) // 100/011/010..
	{
		div = 4;
		num = (int)octal[i] - 48;
		while(div)
		{
			if(num / div)
			{
				binary[cnt] = '1';
				num -= div;
			}
			else
			{
				binary[cnt] = '0';
			}
			cnt++;
			div /= 2;
		}
		binary[cnt] = '\0';
	}
	printf("%s\n", binary);
	return 0;
}
