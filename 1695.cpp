/*1695번 팰린드롬 만들기(C++11)*/
//maybe strlen - LCS?
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int a[5002], b[5002];
int lcs[5002][5002];

int main()
{
	int i, j, Max, lcs_len=0;

	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> a[i];
		//cout << a[i] << endl; //debug
		b[N-i+1] = a[i];
	}
	/* //debug
	   for (i = 1; i <= N; i++) {
	   cout << b[i] << endl;
	   }
	 */ 

	for (i = 1; i <= N; i++) {
		Max = 0;
		for (j = 1; j <= N; j++) {
			if (a[i] == b[j]) {
				Max = lcs[i-1][j-1] + 1;
				lcs[i][j] = Max;
			}
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			Max = max(Max, lcs[i][j]);
		} //for j
		lcs_len = max(lcs_len, Max);
	}// for i
	cout << N - lcs_len << endl;
	return 0;
}
