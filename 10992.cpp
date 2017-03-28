/*10992번 별 찍기 - 17(C++)*/
#include <iostream>
int main(){
	int N, i, j;
	std::cin>>N;
	for(i = 0 ; i < N-1 ; i++){
		for(j = N-i ; j > 1 ; j--)
			std::cout<<" ";
		std::cout<<"*";
		for(j = 0 ; j < 2*i-1 ; j++)
			std::cout<<" ";
		if(i)
			std::cout<<"*";
		std::cout<< std::endl;
	}
	for(i = 0 ; i < 2*N-1 ; i++)
		std::cout<<"*";
	std::cout<< std::endl;
	return 0;
}
