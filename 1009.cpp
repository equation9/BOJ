/*1009번 분산처리(C++)*/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T, a, b, i, res; //a^b
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &a, &b);
		a %= 10;
		res = a;
		for(i = 2 ; i <= b ; i++){
			res *= a;
			res %= 10;
		}
		printf("%d\n", res ? res : res+10);
	}
	return 0;
}
