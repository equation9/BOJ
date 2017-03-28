/*2608번 로마 숫자(C++11)*/
#include <cstdio>
#include <cstring>

char Roma[25];

int RN(char R)
{
	switch(R)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		default : //M
			return 1000;
	}
}

int Roma_to_Num(char rom[])
{
	int sum=0, len = strlen(rom), tmp = RN(rom[0]), item;
	for(int i = 1 ; i < len ; i++)
	{
		item = RN(rom[i]);
		if(tmp < item)
		{
			sum -= tmp;
		}
		else
		{
			sum += tmp;
		}
		tmp = item;
	}
	return sum+tmp;
}

void Num_to_Roma(int num)
{
	int idx=0, tmp;
	/*1000의 자리*/
	tmp = num/1000;
	while(tmp--)
	{
		Roma[idx++] = 'M';
	}
	num %= 1000;

	/*100의 자리*/
	tmp = num / 100;
	if(num >= 900)
	{
		Roma[idx++] = 'C';
		Roma[idx++] = 'M';
	}
	else if(num >= 500)
	{
		Roma[idx++] = 'D';
		tmp-=5;
		while(tmp--)
			Roma[idx++] = 'C';
	}	
	else if(num >= 400)
	{
		Roma[idx++] = 'C';
		Roma[idx++] = 'D';
	}
	else // n < 400
	{
		while(tmp--)
			Roma[idx++] = 'C';
	}
	num %= 100;

	/*10의 자리*/
	tmp = num / 10;
	if(num >= 90)
	{
		Roma[idx++] = 'X';
		Roma[idx++] = 'C';
	}
	else if(num >= 50)
	{
		Roma[idx++] = 'L';
		tmp-=5;
		while(tmp--)
			Roma[idx++] = 'X';
	}
	else if(num >= 40)
	{
		Roma[idx++] = 'X';
		Roma[idx++] = 'L';
	}
	else // 100 <= n < 400
	{
		while(tmp--)
			Roma[idx++] = 'X';
	}
	num %= 10;

	/*1의 자리*/
	if(num >= 9)
	{
		Roma[idx++] = 'I';
		Roma[idx++] = 'X';
	}
	else if(num >= 5)
	{
		Roma[idx++] = 'V';
		num -= 5;
		while(num--)
			Roma[idx++] = 'I';
	}
	else if(num >= 4)
	{
		Roma[idx++] = 'I';
		Roma[idx++] = 'V';
	}
	else
		while(num--)
			Roma[idx++] = 'I';
	Roma[idx] = '\0';
	return;
}

int main()
{
	int i, N, sum=0;
	for(i = 0 ; i < 2 ; i++)
	{
		scanf("%s", Roma);
		sum+=Roma_to_Num(Roma);
	}
	printf("%d\n", sum);
	Num_to_Roma(sum);
	printf("%s\n", Roma);
	return 0;
}
