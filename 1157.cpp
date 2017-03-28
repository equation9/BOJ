/*1157번 단어 공부(C++)*/
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>

static int alphabet[26];

int main()
{
	std::string str;
	int max_order=0, DUPL_FLAG=0, i, Max;
	getline(std::cin, str);
	std::transform(str.begin(), str.end(), str.begin(), toupper);

	for(i = 0 ; i < str.size(); i++)
		alphabet[(int)str[i]-65]++;
	Max = alphabet[0];
	for(i = 1 ; i < 26 ; i++)
	{
		if(alphabet[i] > Max)
		{
			max_order = i;
			Max = alphabet[max_order];
			DUPL_FLAG = 0;
		}
		else if(alphabet[i] == Max)
		{
			DUPL_FLAG = 1;
		}
	}
	printf("%c\n", DUPL_FLAG ? '?' : (char)(max_order+65));
	return 0;
}
