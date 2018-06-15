/*11657번 타임머신(C++11)*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define INF 87654321
int N, M;
vector<pair<int, int> > map[501];
int dist[501];

int main(){
	ios::sync_with_stdio(false);

	int i, j;
	bool _flag=false;
	cin>> N >> M;
	for(i = 1; i <= N; i++) dist[i] = INF;
	
	for(i = 0; i < M; i++){
		int a, b, c;
		cin>> a >> b >> c;
		//cout<< a <<"-"<< b <<": "<< c <<"\n";//debug
		map[a].push_back( {b, c} ); // a->b , c
	}

	dist[1] = 0;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			for(pair<int, int> k : map[j]){
			//	cout<< j <<"-"<< k.first <<": "<< k.second <<"\n";//debug
				if((dist[j] != INF) && (dist[k.first] > k.second + dist[j])){
					dist[k.first] = k.second + dist[j];
					if(i == N) _flag = true;
				}
			}
		}
	}
	if(_flag){
		cout<<"-1\n";
		return 0;
	}
	for(i = 2; i <= N; i++){
		if(dist[i] == INF) cout<<"-1\n";
		else cout<<dist[i]<<"\n";
	}
	return 0;
}
