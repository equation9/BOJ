/*2908번 상수(C++)*/
#include <cstdio>
#include <cstdlib>

void reverse_str(char * str){
	int i;
	char tmp[3];
	for(i = 0 ; i < 3 ; i++){
		tmp[i] = str[2-i];
	}
	for(i = 0 ; i < 3 ; i++){
		str[i] = tmp[i];
	}
}

int main(){
	char str1[4], str2[4];
	int num1, num2;
	scanf("%s %s", str1, str2);
	reverse_str(str1);
	reverse_str(str2);
	num1 = atoi(str1);
	num2 = atoi(str2);
	printf("%d\n", num1 > num2 ? num1 : num2);
}
