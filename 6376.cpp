/*6376번 e 계산(C++11)*/
#include <cstdio>
#include <iostream>
#include <iomanip>
int main()
{
	long double res = 1, div;
	int i, j;
	printf("n e\n- -----------\n0 1\n");
	std::cout.precision(10);
	for(i = 1 ; i <= 9 ; i++)
	{
		div = 1;
		for(j = 1; j <= i ; j++)
			div *=j;
		res += 1 / div;
		std::cout<< i <<" "<< res;
		if(i == 8)
			printf("0");
		printf("\n");
	}
	return 0;
}
