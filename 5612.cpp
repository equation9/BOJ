/*5612번 터널의 입구와 출구(C++11)*/
#include <cstdio>
int main()
{
	int m, n, tmp, max;
	bool _flag = false;
	scanf("%d %d", &n, &m);
	max = m;
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d", &tmp);
		m += tmp;
		scanf("%d", &tmp);
		m -= tmp;

		if(m < 0)
		{
			_flag = true;
		}

		if(m > max) max = m;
	}
	printf("%d\n", _flag ? 0 : max);
	return 0;
}
