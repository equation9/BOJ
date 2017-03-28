/*5218번 알파벳 거리(C++11)*/
#include <cstdio>
#include <cstring>

int main()
{
	char a[1024], b[1024];
	int T, i, len, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s %s", a, b);
		len = strlen(a);
		printf("Distances:");
		for(i = 0 ; i < len ; i++)
		{
			n = b[i] - a[i];
			if(n < 0)
				n += 26;
			printf(" %d", n);
		}
		printf("\n");
	}
	return 0;
}
