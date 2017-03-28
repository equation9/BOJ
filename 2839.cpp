/*2839번 설탕 배달(C++11)*/
#include <iostream>

int main(){
	int N, sum=0, res=-1, tmp, i;
	std::cin>> N;
	i = N/5;

	while(i >= 0){
		tmp = (N % 5) + (i * 5);
		sum = (N - tmp) / 5;
		if(tmp % 3)
			sum = -1;
		else
			sum += tmp/3;
		
		if((sum != -1 && (sum < res)) || (res == -1))
			res = sum;
		i--;
	}

	std::cout<< res <<std::endl;
	return 0;
}
