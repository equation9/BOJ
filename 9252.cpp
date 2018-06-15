/*9252번 LCS 2 (C++11)*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2;
int map[1001][1001];
pair<int, int> back[1001][1001];
int sl1, sl2;


int dp(int i, int j){
	if (sl1 == i || sl2 == j)return 0;
	int& ret = map[i][j];
	if (ret != -1)return ret;
	if (s1[i] == s2[j]) {
		back[i][j] = { i + 1,j + 1 };
		return ret = 1 + dp(i + 1, j + 1);
	}
	int x = dp(i + 1, j);
	int y = dp(i, j + 1);
	if (x > y) {
		back[i][j] = { i + 1,j };
		return ret = x;
	}
	else {
		back[i][j] = { i,j + 1 };
		return ret = y;
	}
}
int main(){
	cin >> s1 >> s2;
	sl1 = s1.size();
	sl2 = s2.size();
	
	memset(map, -1, sizeof(map));
	
	cout<< dp(0, 0) <<endl;
	
	int x, y;
	x = y = 0;
	while (x != sl1 && y != sl2) {
		if (s1[x] == s2[y])
			cout<< s1[x];
		int tx = x;
		x = back[x][y].first;
		y = back[tx][y].second;
	}
	cout<<endl;
	return 0;
}


