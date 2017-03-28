/*5897번 키로거(C++11)*/
#include <cstdio>
#include <cstring>
#include <vector>

/*커서기준 왼쪽 오른쪽*/
std::vector<char> LSTACK;
std::vector<char> RSTACK;
std::vector<char>::iterator iter;

int main()
{
	int i, length;
	long long unsigned T;
	char Input[1000001];
	scanf("%llu", &T);
	while(T--)
	{
		scanf("%s", Input);
		length = strlen(Input);
		LSTACK.clear();
		RSTACK.clear();
		for(i = 0 ; i < length ; i++)
		{
			switch(Input[i])
			{
				case '<':
					if(LSTACK.empty())
						break;
					RSTACK.push_back(LSTACK.back());
					LSTACK.pop_back();
					break;
				case '>':
					if(RSTACK.empty())
						break;
					LSTACK.push_back(RSTACK.back());
					RSTACK.pop_back();
					break;
				case '-':
					if(LSTACK.empty())
						break;
					LSTACK.pop_back();
					break;
				default :
					LSTACK.push_back(Input[i]);
					break;
			}
		}
		for(iter = LSTACK.begin() ; iter != LSTACK.end() ; iter++)
		{
			printf("%c", *iter);
		}
		for(std::vector<char>::reverse_iterator riter = RSTACK.rbegin() ; riter != RSTACK.rend() ; riter++)
		{
			printf("%c", *riter);
		}
		printf("\n");
	}
	return 0;
}
