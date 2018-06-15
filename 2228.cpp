/*2228번 구간나누기(C++11)*/
#include <iostream> 
#include <algorithm> 
#include <cstring> 
using namespace std; 

const int MIN = -2000000000; 
int dp[101][101];
int N, M; 
int arr[101]; 
int sum[101]; 

int solve(int a, int b) 
{

	if(b == 0) return 0; 
	if(a > N || b < 0) return MIN; 
	
	int &res = dp[a][b]; 
	
	if(res != MIN) return res; 

	res = -1000000007; 
	res = max(res, solve(a+1, b)); 
	for(int i = 0; a+i <= N; i++)
		res = max(res, solve(a+i+2, b-1) + sum[a+i] - sum[a-1]); 

	return res; 
}

int main() 
{
	ios::sync_with_stdio(false);
	int i, j;
	for(i = 0; i < 101; i++)
		for(j = 0; j < 101; j++) 
			dp[i][j] = MIN; 
	
	cin>> N >> M;
	
	for(i = 1; i <= N; i++)
		cin>> arr[i];
	for(i = 1; i <= N; i++)
		sum[i] = sum[i-1] + arr[i]; 
	
	cout<< solve(1,M) <<endl;
	return 0;
}
