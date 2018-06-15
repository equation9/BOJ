/*3908번 서로 다른 소수의 합(C++11)*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int pn, cache[1121][188][15];
vector<int> Prime;

int dp(int n, int pos, int k){
	int &res = cache[n][pos][k];
	if(res != -1) return res;
	if(n == 0) return res = (k==0);
	if(k == 0) return res = 0;
	if(pos == pn) return res = 0;
	res = dp(n, pos+1, k);
	if(n >= Prime[pos]) res += dp(n-Prime[pos], pos+1, k-1);
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	Prime.push_back(2); //소수를 담는 벡터
	bool np[1120] = {0};
	int i, j;
	for(i = 3; i < 1120; i += 2){
		if(np[i]) continue;
		Prime.push_back(i);
		for(j = i*i; j < 1120; j += i*2)
			np[j] = true;
	}
	pn = Prime.size();
	reverse(Prime.begin(), Prime.end());
	memset(cache, -1, sizeof(cache));
	int T, t;
	cin>> T;
	for(t = 0; t < T; t++){
		int N, K;
		cin>> N >> K;
		cout<< dp(N,0,K) <<endl;
	}
	return 0;
}
