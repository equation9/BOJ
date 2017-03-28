/*1427번 소트인사이드(C++11)*/
/*STL*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
int main()
{
	char Num[11];
	int len;
	scanf("%s", Num);
	len = strlen(Num);
	std::sort(Num, Num+len, std::greater<char>());
	printf("%s\n", Num);
}
