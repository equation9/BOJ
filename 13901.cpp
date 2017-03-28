/*13901번 로봇(C++)*/
#include <iostream>
#include <vector>

std::vector<std::vector<char> > Map;
std::vector<int> direc;
static int R, C, sr, sc;

bool go_(int d){
	int i, j, x=sr, y=sc;
	switch(d){
		case 1 :
			for(i = sr-1 ; i >= 0 ; i--){
				if(Map[i][sc] == '*'){
					Map[i][sc] = '+';
					sr = i;
				}
				else 
					break;
			}
			break;
		case 2 :
			for(i = sr+1 ; i < R ; i++){
				if(Map[i][sc] == '*'){
					Map[i][sc] = '+';
					sr = i;
				}
				else 
					break;
			}
			break;
		case 3 :
			for(i = sc-1 ; i >= 0 ; i--){
				if(Map[sr][i] == '*'){
					Map[sr][i] = '+';
					sc = i;
				}
				else 
					break;
			}
			break;
		case 4 :
			for(i = sc+1 ; i < C ; i++){
				if(Map[sr][i] == '*'){
					Map[sr][i] = '+';
					sc = i;
				}
				else 
					break;
			}
			break;
	}
	if((sr == R-1 ||Map[sr+1][sc] != '*') && (!sr || Map[sr-1][sc] != '*') && (sc == C-1 || Map[sr][sc+1] != '*') && (!sc || Map[sr][sc-1] != '*'))
		return false;
	return true;
}

int main(){
	int k, i, j;
	std::cin>> R >> C >> k;
	Map.assign(R, std::vector<char>(C, '*'));
	while(k--){
		std::cin>> i >> j;
		Map[i][j] = 'x';
	}
	std::cin>> sr >> sc;
	Map[sr][sc] = '+';
	i = j = 0;
	while(std::cin>> k){
		direc.push_back(k);
		i++;
	}
	while(go_(direc[j])){
		if(j == i-1)
			j = 0;
		else
			j++;
	}
	std::cout<<sr<<" "<<sc<<std::endl;
	return 0;
}
