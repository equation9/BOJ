/*10991번 별 찍기 - 16(C++)*/
#include <iostream>
int main(){
	int N, i, j;
	std::cin>>N;
	for(i = 0 ; i < N ; i++){
		for(j = N-i ; j > 1 ; j--)
			std::cout<<" ";
		for(j = 0 ; j <= i ; j++)
			std::cout<<"* ";
		std::cout<< std::endl;
	}
	return 0;
}
