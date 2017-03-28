/*8958번 OX퀴즈*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int N, corr_cnt, Score, i;
	char Res[81];
	scanf("%d", &N);
	while(N--){
		scanf("%s", Res);
		corr_cnt = Score = 0;
		for(i = 0 ; i < strlen(Res) ; i++){
			if(Res[i] == 'O'){
				corr_cnt++;
			}
			else{
				corr_cnt = 0;
			}
			Score += corr_cnt;
		}
		printf("%d\n", Score);
	}
	return 0;
}
