/*5063번 TGN(C++11)*/
#include <cstdio>
int main()
{
	int T, r, e, c, res_a;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &r, &e, &c);
		res_a = e-c;
		if(r > res_a)
			printf("do not advertise\n");
		else if(r == res_a)
			printf("does not matter\n");
		else //r < res_a
			printf("advertise\n");
	}
	return 0;
}
