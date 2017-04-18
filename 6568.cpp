/*6568번 귀도 반 로썸은 크리스마스날 심심하다고 파이썬을 만들었다(C++11)*/
#include <cstdio>
#include <cstring>
#define C 31

int main()
{
	int i, cnt=0;
	char tmp[9];
	unsigned char pc=0 ,Input[32], Adder=0, cmd, op;
	memset(Input, 0, sizeof(Input));
	while(scanf("%s", tmp) != -1)
	{
		for(i = 0 ; i < 7 ; i++)
		{
			Input[cnt] |= tmp[i]-'0';
			Input[cnt]<<=1;
		}
		Input[cnt] |= tmp[i]-'0';
		cnt++;

		if(cnt == 32)
		{
			while(1)
			{
				pc&=31;
				cmd = Input[pc]>>5;
				op = Input[pc++]&C;
				switch(cmd)
				{
					case 0 : 
						Input[op] = Adder;
						break;
					case 1 : 
						Adder = Input[op];
						break;
					case 2 : 
						if(!Adder) pc = op;
						break;
					case 4 : 
						Adder--;
						break;
					case 5 : 
						Adder++;
						break;
					case 6 : 
						pc = op;
						break;
					case 3 : 
					case 7 : 
						break;
				}

				if(cmd == 7)
				{
					pc = 128;
					for(i = 0 ; i < 8 ; i++)
					{
						if(Adder&pc) printf("1");
						else printf("0");
						pc>>=1;
					}
					printf("\n");
					break;
				}
			}

			pc = 0;
			Adder = 0;
			memset(Input, 0, sizeof(Input));
			cnt = 0;
		}
	}
	return 0;
}
