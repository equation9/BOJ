/*4652번 W's Cipher(C++)*/
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>

int main()
{
	int k[3]; //k1 k2 k3
	int i=0, j, len, next;
	int n[3]; //a~i j~r s~z,_ 갯수
	char tmp, str[101];
	std::pair<int, char> Word[81];
	std::vector<int> Order[3];

	while(1)
	{
		for(i = 0 ; i < 3 ; i++) 
		{
			scanf("%d", &k[i]);
			n[i] = 0;
			Order[i].clear();
		}
	
		if(!k[0] && !k[1] && !k[2]) return 0;
		
		scanf("%s", str);
		len = strlen(str);
		for(i = 0 ; i < len ; i++)
		{
			tmp = str[i];

			Word[i].first = i;
			Word[i].second = tmp;
			if(tmp >= 'a' && tmp <= 'i')
			{
				Order[0].push_back(i);
				n[0]++;
			}
			else if(tmp >= 'j' && tmp <= 'r') 
			{
				Order[1].push_back(i);
				n[1]++;
			}
			else if((tmp >= 's' && tmp <= 'z') || tmp == '_')
			{
				Order[2].push_back(i);
				n[2]++;
			}
		}

		for(i = 0 ; i < 3 ; i++)
		{
			for(j = 0 ; j < n[i] ; j++)
			{
				next = j + k[i];
				while(next >= n[i]) next -= n[i];
				//printf("%c : %d->%d\n", Word[Order[i][j]].second, Word[j].first, Order[i][next]);//디버깅
				Word[Order[i][j]].first = Order[i][next];
			}
		}
		std::sort(Word, Word + len);
		for(i = 0 ; i < len ; i++)
			printf("%c", Word[i].second);
		printf("\n");
	}
	return 0;
}
