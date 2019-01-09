/*13939번 Imena(C++11)*/
#include <cstdio>
#include <cstring>

char str[2001];
int N;
int arr[6];
bool _flag;

bool des_word(char c){
	return (c == ' ' || c == '\n' || c == 0x00);
}

bool des_sent(char c){
	return (c == '.' || c == '!' || c == '?');
}

int main()
{
	int i=0, j=0;
	int len;
	scanf("%d ", &N);
	fgets(str, 2001, stdin);
	//printf("%s\n", str);//debug
	while(str[i] != '\n' && str[i] != 0x00){
		if(j >= N) break;
		if(des_word(str[i]) || des_sent(str[i])){
			i++;
			continue;
		}
		//printf("%c\n", str[i]);//debug

		if(str[i] >= 'A' && str[i] <= 'Z'){
			_flag = true;

			i++;
			while(!des_sent(str[i]) && !des_word(str[i])){
				if(str[i] < 'a' || str[i] > 'z'){
					_flag = false;
				}
				i++;
			}
			if(_flag) arr[j]++;
			if(des_sent(str[i])) j++;
			continue;
		}

		while(!des_word(str[i]) && !des_sent(str[i]))
			i++;
		if(des_sent(str[i])) j++;
	}
	for(i = 0; i < N; i++)
		printf("%d\n", arr[i]);
	return 0;
}
