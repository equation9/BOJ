/*10102번 개표(C++11)*/
#include <cstdio>
int main()
{
	bool _flag=false;
	int N, i, A, B;
	char Str[16];
	A = B = 0;
	scanf("%d %s", &N, Str);
	for(i = 0 ; i < N ; i++)
	{
		if(Str[i] == 'A') A++;
		else B++;
	}
	if(A == B) printf("Tie\n");
	else if(A > B) printf("A\n");
	else  printf("B\n");
	return 0;
}
