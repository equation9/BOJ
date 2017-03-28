/*5622번 다이얼(C++)*/
#include <cstdio>
#include <cstring>
static int alph[26];
void init()
{
	int i, j=3;
	for(i = 0 ; i < 3 ; i++)
		alph[i] = j;
	j++;
	for(i ; i < 6 ; i++)
		alph[i] = j;
	j++;
	for(i ; i < 9 ; i++)
		alph[i] = j;
	j++;
	for(i ; i < 12 ; i++)
		alph[i] = j;
	j++;
	for(i ; i < 15 ; i++)
		alph[i] = j;
	j++;
	for(i ; i < 19 ; i++)
		alph[i] = j;
	j++;
	for(i ; i < 22 ; i++)
		alph[i] = j;
	j++;
	for(i ; i < 26 ; i++)
		alph[i] = j;
}

int main()
{
	int i, sum=0;
	char order[16];
	scanf("%s", order);
	init();
	for(i = 0 ; i < strlen(order) ; i++)
	{
		sum += alph[(int)order[i] - 65];
	}
	printf("%d\n", sum);
	return 0;
}
