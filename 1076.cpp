/*1076번 저항(C++)*/
#include <cstdio>
#include <cstring>

int color_val(char name[])
{
	int val;
	if(!strncmp(name, "black", 5))
		val = 0;
	else if(!strncmp(name, "brown", 5))
		val = 1;
	else if(!strncmp(name, "red", 3))
		val = 2;
	else if(!strncmp(name, "orange", 6))
		val = 3;
	else if(!strncmp(name, "yellow", 6))
		val = 4;
	else if(!strncmp(name, "green", 5))
		val = 5;
	else if(!strncmp(name, "blue", 4))
		val = 6;
	else if(!strncmp(name, "violet", 6))
		val = 7;
	else if(!strncmp(name, "grey", 5))
		val = 8;
	else if(!strncmp(name, "white", 5))
		val = 9;
	return val;
}

int main()
{
	char ohm[12], color[10];
	int n, i, idx=0, zero_cnt=0;
	scanf("%s", color);
	n = color_val(color);
	if(n)
		ohm[idx++] = (char)n+48;
	else zero_cnt++;
	
	scanf("%s", color);
	n = color_val(color);
	ohm[idx++] = (char)n+48;
	if(!n)
		zero_cnt++;
	
	scanf("%s", color);
	n = color_val(color);
	if(zero_cnt != 2)
		for(i = 0 ; i < n ; i++)
			ohm[idx++] = '0';
	ohm[idx] = '\0';
	printf("%s\n", ohm);
	return 0;
}
