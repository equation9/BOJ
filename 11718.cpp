/*11718번 그대로 출력하기(C++)*/
#include <iostream>

int main(){
	char str[101];
	while(std::cin.getline(str, 101))
		std::cout<<str<<std::endl;
	return 0;
}
