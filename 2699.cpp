/*2699번 격자점 컨벡스헐(C++11)*/
/*제곧내*/
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX_N 50
typedef std::pair<long long int, long long int> Pair;

int T, N;
Pair p[MAX_N];
std::vector<Pair > S;

void swap(int a, int b){
	long long int tmp = p[a].first;
	p[a].first = p[b].first;
	p[b].first = tmp;
	
	tmp = p[a].second;
	p[a].second = p[b].second;
	p[b].second = tmp;
	return;
}

long long int dist(Pair a, Pair b){
	long long int x = a.first - b.first;
	long long int y = a.second - b.second;
	return x*x + y*y;
}


long long int ccw(Pair a, Pair b, Pair c){
	long long int ret = (a.first - c.first)*(b.second - c.second) - (b.first - c.first)*(a.second - c.second);
	
	//printf("ret : %lld ccw: (%lld, %lld), (%lld, %lld), (%lld, %lld)\n", ret, c.first, c.second, a.first, a.second, b.first, b.second);//debug
	return ret;
}

bool cmp( Pair a,  Pair b){
	long long int ret = ccw(a, b, p[0]);
	if(ret > 0) return true;
	if(ret < 0) return false;
	if(dist(a, p[0]) < dist(b, p[0])) return true;
	return false;

}

int main()
{
	int i, j;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		
		int min = 0;
		for(i = 0; i < N; i++){
			scanf("%lld%lld", &p[i].first, &p[i].second);
			if(p[i].second > p[min].second || p[i].second == p[min].second && p[i].first < p[min].first)
				min = i;
		}
		swap(0, min);
		std::sort(p+1, p+N, cmp);
		
		
		/*
		for(i = 0; i < N; i++)//debug
			printf("(%lld, %lld) ", p[i].first, p[i].second);
		printf("\n");
		*/

		
		S.push_back(p[0]);
		S.push_back(p[1]);
		
		for(i = 2 ; i < N; i++){
			while((S.size() >= 2) && (ccw(S[S.size()-1], p[i], S[S.size()-2]) <= 0))
				S.pop_back();
			S.push_back(p[i]);
		}
		
		printf("%d\n", S.size());
		printf("%lld %lld\n", p[0].first, p[0].second);

		while(S.size()){
			Pair now = S.back();
			S.pop_back();
			if(!S.size()) break;
			printf("%lld %lld\n", now.first, now.second);
		}
		S.clear();
	}
	return 0;
}
