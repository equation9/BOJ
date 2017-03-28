/*10809번 알파벳 찾기*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char Word[101];
	int alphabet[26][2], i, alph;
	for(i = 0 ; i < 26; i++){
		alphabet[i][1] = -1;
		alphabet[i][0] = 0;
	}
	scanf("%s", Word);

	for(i = 0 ; i < strlen(Word) ; i++)
	{
		alph = (int)Word[i] - 97;
		if(!alphabet[alph][0])
		{
			alphabet[alph][1] = i;
			alphabet[alph][0]++;
		}
	}

	for(i = 0 ; i < 26 ; i++)
		printf("%d ", alphabet[i][1]);
	printf("\n");
	return 0;
}
