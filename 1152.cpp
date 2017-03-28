#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int i=0, cnt=0;
	char str[1000001];
	cin.getline(str, 1000001);

	if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
		while((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
			i++;	
		}
		cnt++;
	}

	for(i ; i < strlen(str) ; i++){
		if(str[i] == ' '){
			if((str[i+1] >= 'a' && str[i+1] <= 'z') || (str[i+1] >= 'A' && str[i+1] <= 'Z')){
				i++;
				while((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
					i++;
				}
				i--;
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
