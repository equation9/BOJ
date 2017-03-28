/*1978번 소수 찾기(C++)*/
#include <iostream>
#include <cstdio>
using namespace std;

int Is_it_prime(int n){
	int i, cnt=0;
	if(n == 1)
		return 0;
	for(i = 1 ; i <= n ; i++)
		if(!(n % i))
			cnt++;
	return (cnt == 2 ? 1 : 0);
}

int main(){
	int N;
	scanf("%d", &N);
	int num, i, cnt=0;
	for(i = 0 ; i < N ; i++){
		scanf("%d", &num);
		if(Is_it_prime(num))
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
