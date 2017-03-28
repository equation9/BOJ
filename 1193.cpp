/*1193번 분수찾기*/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int Num, denom, numer;
	int i=1, sum=0, order=0;
	scanf("%d", &Num);
	
	while(sum < Num){
		sum += i;
		i++;
		order++;
	}
	
	if(order % 2) //홀수
	{
		numer = 1+sum-Num;
		denom = order-sum+Num;
	}
	else //짝수
	{
		numer = order-sum+Num;
		denom = 1+sum-Num;
	}
	printf("%d/%d\n", numer, denom);
	return 0;
}
