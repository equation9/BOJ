/*1074번 Z(C++11)*/
#include <iostream>
using namespace std;

long int N, R, C;
bool END_FLAG;

long int roll_pow(long int a) 
{
	long int i, tmp = 1;
	for (i = 1; i <= a; i++)
		tmp *= 2;
	return tmp;
}

long int DQ(long int r, long int c, long int d) {
	long int cnt = 0;

	if (END_FLAG) return 0;
	if (d == 1) {
		if (r == R && c == C) END_FLAG = true;
		return 1;
	}

	if ((R < r + d / 2) &&(C < c + d / 2)) { //1
			cnt += DQ(r, c, d / 2);
			return cnt;
	}
	cnt += (d/2) * (d/2);

	if ((R < r + d / 2) && (C >= c + d / 2)) { //2
		cnt += DQ(r, c+d/2, d / 2);
		return cnt;
	}
	cnt += (d / 2) * (d / 2);
	
	if ((R >= r + d / 2) && (C < c + d / 2)) { //3
		cnt += DQ(r+d/2, c, d / 2);
		return cnt;
	}
	cnt += (d / 2) * (d / 2);
	
	if ((R >= r + d / 2) && (C >= c + d / 2)) { //4
		cnt += DQ(r + d / 2, c +d/2, d / 2);
		return cnt;
	}
}

int main() 
{
	cin >> N >> R >> C;
	cout << DQ(0, 0, roll_pow(N))-1 << endl;
	return 0;
}
