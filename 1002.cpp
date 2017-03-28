/*1002번 터렛(C++)*/
#include <cstdio>
#include <cmath>
int main()
{
	int T, r1, r2, res;
	long double x1, y1, x2, y2, dist;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%Lf %Lf %d", &x1, &y1, &r1);
		scanf("%Lf %Lf %d", &x2, &y2, &r2);
		dist = sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
		
		if(!dist) //중심의 좌표가 동일
			if(r1-r2) 
				res = 0; //반지름 길이가 다름
			else 
				res = -1; //동일한 원
		else //중심의 좌표가 다름
		{
			if(dist < r1+r2)
			{
				if(dist < std::abs(r1-r2))
					res = 0;
				else if(dist == std::abs(r1-r2))
					res = 1;
				else // >
					res = 2;
			}
			else if(dist == r1+r2)
				res = 1;
			else
				res = 0;
		}
		printf("%d\n", res);
	}
	return 0;
}
