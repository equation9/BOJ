/*8794번 희주의 수학시험(C++11)*/
#include <cstdio>

int num[1001];

int main()
{
	int a, b, i, res=0, cnt=0, s=1;
	scanf("%d %d", &a, &b);
	for(i = 1; i <= b ; i++)
	{
		if(i >= a) res += s;
		cnt++;
		if(cnt == s)
		{
			s++;
			cnt =0;
		}
	}
	printf("%d\n", res);
	return 0;
}
