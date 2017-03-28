/*11655번 ROT13(C++11)*/
#include <cstdio>
#include <cstring>
#include <iostream>

int main()
{
	int i;
	char S[102];
	std::cin.getline(S, sizeof(S));
	for(i = 0 ; i < strlen(S) ; i++)
	{
		if((S[i] < 'A' || S[i] > 'Z') && (S[i] < 'a' || S[i] > 'z'))
			continue;
		if(S[i] > 'm' || (S[i] > 'M' && S[i] <= 'Z'))
			S[i] -= 13;
		else
			S[i] += 13;
	}
	printf("%s\n", S);
	return 0;
}
