/*11648번 지속(C++11)*/
#include <cstdio>
#include <cstring>
int main()
{
	int N, cnt=0, l;
	char buf[10];
	scanf("%s", buf);
	l = strlen(buf);
	while(l > 1)
	{
		N = 1;
		for(int i= 0 ; i < l ; i++)
		{
			N *= (int)(buf[i] - '0');
		}
		cnt++;
		sprintf(buf, "%d", N);
		l = strlen(buf);
	}
	printf("%d\n", cnt);
	return 0;
}
