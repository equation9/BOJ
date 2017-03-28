/*2902번 KMP는 왜 KMP일까?(C++11)*/
#include <cstdio>
#include <cstring>

int main()
{
	char name[101];
	scanf("%s", name);
	for(int i=0 ; i < strlen(name) ; i++)
		if(name[i] >= 'A' && name[i] <='Z')
			printf("%c", name[i]);
	printf("\n");
	return 0;
}
