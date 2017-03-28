/*10808번 알파벳 개수(C++)*/
#include <cstdio>
#include <cstring>

static int alph[26];

int main()
{
	int i;
	char S[101];
	scanf("%s", S);
	for(i = 0 ; i < strlen(S) ; i++)
		alph[(int)S[i]-97]++;
	for(i = 0 ; i < 26 ; i++)
		printf("%d ", alph[i]);
	printf("\n");
	return 0;
}
