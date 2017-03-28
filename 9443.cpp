/*9443번 Arrangement of Contes(C++11)*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N, i, cnt=0;
	string Str[100];
	cin>> N;
	for(i = 0 ; i < N ; i++) cin>> Str[i];
	sort(Str, Str+N);
	if(Str[0][0] != 'A')
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(i = 0 ; i < N ; i++)
	{
		//cout<<"String : "<< Str[i] <<endl; //디버깅
		if(Str[i][0]-'A' == cnt)
			cnt++;
	}
	cout<< cnt <<endl;
	return 0;
}
