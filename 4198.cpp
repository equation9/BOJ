/*4198번 열차정렬(C++11)*/
#include <iostream>
#include <algorithm>

using namespace std;

int Train[2001], Max[2001], Min[2001];
int N;

int main()
{
	int i, j, res=0;

	cin>> N;
	for(i = 0; i < N; i++)
		cin>> Train[i];

	for(i = N-1; i >= 0; i--){
		Max[i] = Min[i] = 1;

		for(j = i+1; j < N; j++){
			if(Train[i] > Train[j] && Max[j] + 1 > Max[i])
				Max[i] = Max[j] + 1;
			if(Train[i] < Train[j] && Min[j] + 1 > Min[i])
				Min[i] = Min[j] + 1;
		}
	}

	for(i = 0; i < N; i++)
		res = max(res, Max[i] + Min[i]-1);
	cout<< res <<endl;
	return 0;
}
