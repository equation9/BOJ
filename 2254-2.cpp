/*2254번 감옥 건설(C++11)*/
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Point{
	double x, y;
	double p, q;
	Point(){
		p = 0.0, q = 0.0;
	};
	Point(double x, double y) : x(x), y(y){
		p = 0.0, q= 0.0;
	}
	int getccw(Point a, Point b){
		double tmp = this->x*a.y + a.x*b.y + b.x*this->y - this->y*a.x - a.y*b.x - b.y*this->x;
		if(tmp > 0) 
			return 1;
		else if (tmp == 0)
			return 0;
		else
			return -1;
	}
	bool operator<(const Point &b){
		if(q*b.p != p*b.q)
			return q*b.p < p*b.q;
		return y == b.y ? x < b.x : y < b.y;
	}
};

int N, r;
double Px, Py;
int vst[1010];
vector<Point> V;
Point p;

bool CH()
{
	int next = 2;
	bool res;

	memset(vst, 0, sizeof(vst));
	stack<int> S;
	S.push(0);
	S.push(1);

	while(next < V.size())
	{
		while(S.size() >= 2)
		{
			int a1, a2;
			a1 = S.top();
			S.pop();
			a2 = S.top();
			if(V[a2].getccw(V[a1], V[next]) > 0){
				S.push(a1);
				break;
			}

		}
		S.push(next++);
	}

	res = S.size() > 2 ? 1 : 0;
	vector<int> vec;
	while(S.size())
	{
		vec.push_back(S.top());
		S.pop();
	}
	int dft = p.getccw(V[vec[vec.size() -1]], V[vec[0]]);
	bool f = 0;
	for (int i = 0; i < vec.size() - 1; i++) {
		if (dft != p.getccw(V[vec[i]], V[vec[i + 1]])) {
			f = 1;
			break;
		}
	}
	if(!f) r++;
	for(auto next : vec)
		vst[next] = 1;
	vector<Point> tmp;
	for (int i = 0; i < V.size(); i++) {
		if (!vst[i])
			tmp.push_back(V[i]);
	}
	V.clear();
	for (auto next : tmp)
		V.push_back(next);
	return res;
}


void getslope() {
	sort(V.begin(), V.end());    
	for (int i = 0; i < V.size(); i++) {
		V[i].p = V[i].x - V[0].x;
		V[i].q = V[i].y - V[0].y;
	}
	auto it = V.begin();
	it++;
	sort(it, V.end());
}

int main()
{
	int i;
	ios::sync_with_stdio(false);
	cin>> N >> Px >> Py;

	p = Point(Px, Py);
	for(i = 0; i < N; i++){
		double x, y;
		cin>> x >> y;
		V.push_back(Point(x,y));
	}

	while(1)
	{
		if(V.size() < 3) break;
		getslope();
		bool c = CH();
		if(!c) break;
	}

	cout<< r <<"\n";
	return 0;
}
