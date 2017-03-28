/*8320번 직사각형을 만드는 방법(C++11)*/
#include <cstdio>
#include <cmath>

int main()
{
	int n, i, j, cnt=1, root;
	
	scanf("%d", &n);
	for(i = 2 ; i <= n ; i++)
	{
		root = (int)sqrt((double)i);
		for(j = 1 ; j <= root ; j++)
		{
			if(!(i%j))
				cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
