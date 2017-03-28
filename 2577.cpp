/*2577번 숫자의 개수*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

static int num_cnt[10];

int main(){
	int i, Mul=1, temp;
	char buffer[1042];
	for(i = 0 ; i < 3 ; i++){
		scanf("%d", &temp);
		Mul *= temp;
	}
	snprintf(buffer, 1042, "%d", Mul);
	for(i = 0 ; i < strlen(buffer) ; i++)
		num_cnt[(int)buffer[i] - 48]++;
	for(i = 0 ; i <= 9 ; i++)
		printf("%d\n", num_cnt[i]);

	return 0;
}
