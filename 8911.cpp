/*8911번 거북이(C++11)*/
#include <cstdio>
#include <cstring>

int mx, my, Mx, My, x, y;

void move(int d, int fb)
{
	switch(d)
	{
		case 1 :
			y += fb;
			if(My < y)
				My = y;
			if(my > y)
				my = y;
			break;
		case 2 :
			x += fb;
			if(mx > x)
				mx = x;
			if(Mx < x)
				Mx = x;
			break;
		case 3 :
			y -= fb;
			if(My < y)
				My = y;
			if(my > y)
				my = y;
			break;
		case 4 :
			x -= fb;
			if(mx > x)
				mx = x;
			if(Mx < x)
				Mx = x;
			break;
	}
}

int main()
{
	int i, T,len, dir; //1상2우3하4좌
	char str[501];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", str);
		Mx = My = mx = my = x = y = 0;
		len = strlen(str);
		dir = 1;
		for(i = 0 ; i < len ; i++)
		{
			switch(str[i])
			{
				case 'F' :
					move(dir, 1);
					break;
				case 'B' :
					move(dir, -1);
					break;
				case 'L' :
					if(dir == 1)
						dir = 4;
					else
						dir--;
					break;
				case 'R' :
					if(dir == 4)
						dir = 1;
					else
						dir++;
					break;
			}
		}
		printf("%d\n", (Mx-mx)*(My-my));
	}
	return 0;
}
