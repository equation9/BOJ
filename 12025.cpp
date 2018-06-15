/*12025번 장난꾸러기 영훈(C++11)*/
#include <iostream>
#include <cstring>
using namespace std;

char Pass[61];
long long int k;
int pos[61];

int main()
{
	ios::sync_with_stdio(false);

	cin>> Pass >> k;
	int i, len = strlen(Pass), idx=0;
	long long int tmp = 1;

	for(i = 0 ; i < len ; i++){
		if(Pass[i] == '1' || Pass[i] == '6') {
			pos[idx++] = i;
			Pass[i] = '1';
			tmp *= 2;
		}
		else if(Pass[i] == '2' || Pass[i] == '7'){
			pos[idx++] = i;
			Pass[i] = '2';
			tmp *= 2;
		}
	}
	if(tmp < k){
		cout<<"-1"<<endl;
		return 0;
	}

	k--;
	tmp = 1;
	for(i = idx-1 ; i >= 0 ; i--){
		if(tmp & k){
			if(Pass[pos[i]] == '1') Pass[pos[i]] = '6';
			else if(Pass[pos[i]] == '2') Pass[pos[i]] = '7';
			//cout<<"tmp="<< idx-1-i <<endl<< Pass <<endl; //debug
		}
		tmp *= 2;
	}
	cout<< Pass <<endl;
	return 0;
}
