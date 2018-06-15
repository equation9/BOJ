/*1708번 볼록 껍질(C++11)*/
/*컨벡스 헐*/
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

typedef std::pair<long long int, long long int> Pair;

int N;
Pair p[100001];
std::vector<Pair > v;

long long int dist(Pair a, Pair b){
	long long int x = a.first-b.first;
	long long int y = a.second-b.second;
	return x*x + y*y;
}

long long int ccw(Pair a, Pair b, Pair c){
	long long int ret = (a.first-c.first)*(b.second-c.second) - (a.second-c.second)*(b.first-c.first);
//	printf("ccw(%lld, %lld), (%lld, %lld)res = %lld\n", a.first, a.second, b.first, b.second, ret);//debug
	return ret;
}

bool cmp(const Pair &a, const Pair &b){
	long long int ret = ccw(a, b, p[0]);

	if(ret > 0) return true;
	if(ret < 0) return false;
	if (dist(p[0], a) < dist(p[0],b))
		return true;
	else 
		return false;
}

void swap(int a, int b){
	int tmp = p[a].first;
	p[a].first = p[b].first;
	p[b].first = tmp;
	
	tmp = p[a].second;
	p[a].second = p[b].second;
	p[b].second = tmp;
	return;
}

int main()
{
	int i;
	int min=0;
	scanf("%d", &N);
	for(i = 0 ; i < N; i++){
		scanf("%lld %lld", &p[i].first, &p[i].second);
		if(p[i].second < p[min].second || p[i].second == p[min].second && p[i].first < p[min].first)
			min =i;
	}
	swap(0, min);
	std::sort(p+1, p+N, cmp);

	
	/*
	for(i = 0 ; i < N ; i++)//debug
		printf("(%lld, %lld) ", p[i].first, p[i].second);
	printf("\n");
*/

	v.push_back(p[0]);
	v.push_back(p[1]);
	for(i = 2; i < N; i++){
		while(v.size()>= 2 && (ccw(v.back(), p[i], v[v.size()-2]) <= 0))
			v.pop_back();
		v.push_back(p[i]);
	}

/*	
	for(i = 0 ; i < v.size() ; i++)//debug
		printf("(%lld, %lld) ", v[i].first, v[i].second);
	printf("\n");
*/

	printf("%lu\n", v.size());
	return 0;
}
