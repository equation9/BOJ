/*1181번 단어 정렬(C++11)*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Dict{
	char sentence[80];
	int len;
	bool operator<(Dict b){
		if(this->len < b.len)
			return true;
		else if(this->len == b.len)
		{
			if(strncmp(this->sentence, b.sentence, len) < 0)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	bool operator==(Dict &b){
			return !strcmp(this->sentence, b.sentence);;
	}
};

int main(){
	int temp, N, i;
	scanf("%d", &N);
	vector<Dict> eng;
	vector<Dict>::iterator idx;
	eng.resize(N);
	for(i = 0 ; i < N; i++){
		scanf("%s", eng[i].sentence);
		eng[i].len = strlen(eng[i].sentence);
	}
	sort(eng.begin(), eng.end());
	idx = unique(eng.begin(), eng.end());
	eng.resize(distance(eng.begin(), idx));
	for(auto idx : eng)
		printf("%s\n", idx.sentence);
	return 0;
}
