/*8949번 대충 더해(C++11)*/
#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
	char A[10], B[10], tmp[50];
	int i, num, alen, blen, Max;
	scanf("%s %s", A, B);
	alen = strlen(A);
	blen = strlen(B);
	Max = std::max(alen, blen);
	num = Max - alen;
	while(num--)
	{
		strncpy(tmp, "0", 2);
		strncat(tmp, A, 10);
		strncpy(A, tmp, 10);
	}
	num = Max - blen;
	while(num--)
	{
		strncpy(tmp, "0", 2);
		strncat(tmp, B, 10);
		strncpy(B, tmp, 10);
	}
	for(i = 0 ; i < Max ; i++)
	{
		num = (int)A[i]+(int)B[i] - '0' - '0';
		printf("%d", num);
	}
	printf("\n");
	return 0;
}
