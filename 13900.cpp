/*13900번 순서쌍 곱의 합(C++)*/
#include <iostream>
#include <cstdio>
#include <vector>

int main(){
	long long int N, i, tmp, sum=0, res=0;
	std::cin>> N;
	std::vector<int> v;
	for(i = 0 ; i <  N ; i++)
	{
		std::cin>> tmp;
		sum += tmp;
		v.push_back(tmp);
	}
	for(i = 0 ; i <  N ; i++)
	{
		res += v[i]*(sum - v[i]);
	//	std::cout<<"v["<<i<<"] : "<< v[i] <<" res : "<< res <<std::endl;
	}
	std::cout<< res/2 <<std::endl;
	return 0;
}
