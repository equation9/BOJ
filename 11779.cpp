/*11779번 최소비용 구하기2(C++11)*/
#include <iostream>
#include <stack>

#define INF 99999999
using namespace std;

int N, M, S, E;
int map[1001][1001];
int prv[1001], dist[1001];
bool visit[1001];

int main()
{
	ios::sync_with_stdio(false);

	int i, j;
	cin>> N >> M;
	for(i = 1; i <= N; i++){
		dist[i] = INF;
		for(j =1; j <= N; j++){
			if(i == j) continue;
			else map[i][j] = INF;
		}
	}

	for(i = 0; i < M; i++){
		int a, b, c;
		cin>> a >> b >> c;
		if(map[a][b] > c)
			map[a][b] = c;
	}
	cin>> S >> E;

	dist[S] = 0;
	int min, p;
	for(i = 1; i <= N; i++){
		min = INF;
		for(j = 1; j <= N; j++){
			if(!visit[j] && (dist[j] < min)){
				min = dist[j];
				p = j;
			}
		}
		visit[p] = true;

		for(j = 1; j <= N; j++){
			if(dist[p]+map[p][j] < dist[j]){
				dist[j] = dist[p]+map[p][j];
				prv[j] = p;
			}
		}
	}
	cout<< dist[E] <<"\n";

	stack<int> st;
	int tmp = E;
	while(1){
		st.push(tmp);
		if(tmp == S) break;
		tmp = prv[tmp];
	}
	cout<< st.size()<<"\n";

	while(!st.empty()){
		cout<< st.top() <<" ";
		st.pop();
	}
	cout<<"\n";
	return 0;
}
