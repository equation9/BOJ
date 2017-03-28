/*12833번 XORXORXOR(C++)*/
#include <cstdio>
int main()
{
	int A,B,C;
	scanf("%d%d%d", &A, &B, &C);
	while(C--)
	{
		A ^= B;
	}
	printf("%d\n", A);
	return 0;
}
