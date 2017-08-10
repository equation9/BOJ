/*13567번 로봇(C++11)*/
#include <cstdio>
#include <cstring>

int N, Dir=1, X=0, Y=0;
int ydir[4] = {1, 0, -1, 0};
int xdir[4] = {0, 1, 0, -1};
bool _flag = false;

int main()
{
	int n, o, i;
	char order[5];
	scanf("%d %d", &N ,&n);
	for(i = 0 ; i < n ; i++)
	{
		scanf("%s %d", order, &o);
		if(!strncmp(order, "MOVE", 4))
		{
			Y += o*ydir[Dir];
			X += o*xdir[Dir];
		//	printf("(%d, %d)\n", X, Y);//디버그
			if(X < 0 || X > N || Y < 0 || Y > N)
				_flag = true;
		}
		else //TURN
		{
			if(o)
			{
				Dir++;
				if(Dir >= 4) Dir = 0;
			}
			else //왼쪽으로 회전
			{
				Dir--;
				if(Dir < 0) Dir = 3;
			}
		}
	}
	if(_flag) printf("-1\n");
	else printf("%d %d\n", X, Y);

	return 0;
}
