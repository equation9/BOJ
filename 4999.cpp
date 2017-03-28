/*4999번 아!(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	char pa[1001], doc[1001];
	scanf("%s %s", pa, doc);
	if(strlen(pa) >= strlen(doc))
		printf("go\n");
	else	
		printf("no\n");
	return 0;
}
