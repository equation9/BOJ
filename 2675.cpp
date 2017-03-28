/*2675번 문자열 반복*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int T, cnt, i, j;
	char buffer[21];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s", &cnt, buffer);
		for(i = 0 ; i < strlen(buffer) ; i++)
			for(j = 0 ; j < cnt ; j++)
				printf("%c", buffer[i]);
		printf("\n");
	}
	return 0;
}
