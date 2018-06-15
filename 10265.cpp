/*10265번 MT(C++11)*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N, K;
int buddy[1002];
vector<vector<int>> rbuddy; //역그래프
bool visit[1002];
stack<int> S;

int scccnt; //scc 그룹개수
int group[1002], scc[1002]; //i가 해당하는 scc번호, scc의 인자갯
int cost[1002], scost[1002];

vector<vector<int>> TS; //scc간 연결그래프
int Tcnt[1002];

int setcnt;
int ds[1002],de[1002], dp[1002][1002];

/*SCC*/
void dfs1(int n){
	if(visit[n]) return;
	visit[n] = true;
	
	dfs1(buddy[n]);
	S.push(n);
	return;
}

void dfs2(int n){
	if(visit[n]) return;
//	cout<< n <<" -> "; //debug
	visit[n] = true;
	group[n] = scccnt;
	scc[scccnt]++;

	for(int next : rbuddy[n])
		dfs2(next);
	return;
}
/**/

int dfs3(int n){
	int ret = scost[n];
	for(int next : TS[n]){
		scost[n] += scost[next];
		dfs3(next);
	}
	return ret;
}

int KS(int p, int v){
	if(p > setcnt) return 0;
	if(dp[p][v] != -1) return dp[p][v];
	
	int ret = KS(p+1, v);
	if(v >= ds[p]){
		for(int i = ds[p]; i <= de[p]; i++){
			if(i > v) break;
			ret = max(ret, KS(p+1, v-i)+i);
			//cout<<p<<","<<v<<"/KS/ret : "<< ret <<"\n";//debug
		}
	}
	return dp[p][v] = ret;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int i;
	cin>> N >> K;
	rbuddy.resize(N+1);
	for(i = 1; i <= N; i++){
		cin>> buddy[i];
		rbuddy[buddy[i]].push_back(i);
	}
	//scc
	for(i = 1; i <= N; i++){
		dfs1(i);
	}
	memset(visit, false, sizeof(visit));	
	while(!S.empty()){
		int t = S.top();
		S.pop();
		if(visit[t]) {
		//	cout<<"\n"; //debug
			continue;
		}
		//cout<<"\n<"<< scccnt+1 <<">\n"; //debug
		scccnt++;
		dfs2(t);
	//	cout<<"\ngroup : "<< group[scccnt] <<"\n"; //debug
	}
	//cout<< scccnt <<"\n";//debug
	//scc

	/*debug========================
	for(i = 0; i < scccnt; i++){
		for(int j : scc[i]){
			cout<< j <<"-> ";
		}
		cout<<"\n";
	}
	=============================*/
	TS.resize(scccnt+1);
	for(i = 1; i <= N; i++){
	//	cout<<"group["<< i <<"] : "<< group[i] <<"\n";//debug
		for(int next : rbuddy[i]){
			if(group[i] == group[next]) continue;
			//cout<<"TS["<< group[i] <<"].push_back("<<group[next]<<")\n";//debug
			TS[group[i]].push_back(group[next]);
			Tcnt[group[next]]++;
			//cout<<"Tcnt["<< group[next] <<"] : "<< Tcnt[group[next]] <<"\n";//debug
		}
	}

	for(i = 1; i <= scccnt; i++){
		cost[i] = scost[i] = scc[i];
	//	cout<<"scc["<< i <<"] : "<< scc[i] <<"\n"; //debug
	}
	for(i = 1; i <= scccnt; i++)
		dfs3(i);
	for(i = 1; i <= scccnt; i++){
		if(!Tcnt[i]){
			setcnt++;
			ds[setcnt] = cost[i];
			de[setcnt] = scost[i];
			//cout<<"ds["<<setcnt<<"] :"<< ds[setcnt] <<" de["<< setcnt <<"] : "<< de[setcnt] <<"\n";//debug
		}
	}
	memset(dp, -1, sizeof(dp));
	cout<< KS(1, K) <<"\n";
	return 0;
}
