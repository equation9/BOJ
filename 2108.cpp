/*2108번 통계학(C++11)*/
#include <cstdio>
#include <vector>
#include <algorithm>
struct s{
	long long int cnt;
	long long int num;

	bool operator <(const s &b){
		if(this->cnt == b.cnt)
			return this->num < b.num;
		return this->cnt > b.cnt;
	}
};
long long int N, n[8001];
std::vector<s> arr;

int main()
{
	long long int i;
	long long int cnt1, cnt2, min, max;
	long long int res1, res2, res3;
	scanf("%lld", &N);
	for(i = 0 ; i < N; i++){
		long long int a;
		scanf("%lld", &a);
		n[a+4000]++;
	}

	cnt1 = cnt2 = 0;
	max = -4000;
	min = 4001;
	for(i = 0 ; i <= 8000; i++){
		if(!n[i]) continue;
		
		if(min == 4001) min = i-4000;
		max = i-4000;
		cnt1 += (i-4000)*n[i];
		if((cnt2 <= N/2) && (cnt2+n[i] > N/2)) 
			res2 = i-4000;
		cnt2 += n[i];
		arr.push_back({n[i], i-4000});
	}
	//1
	res1 = ((cnt1*10)/N)%10;
	//printf("---res1 : %d\n", res1);//debug
	if(res1 >= 5)
		res1 = cnt1/N+1;
	else if(res1 <= -5)
		res1 = cnt1/N-1;
	else
		res1 = cnt1/N;

	//2
	std::sort(arr.begin(), arr.end());
	if(N >1 && (arr[0].cnt == arr[1].cnt))
		res3 = arr[1].num;
	else
		res3 = arr[0].num;

	printf("%lld\n", res1);
	printf("%lld\n", res2);
	printf("%lld\n", res3);
	printf("%lld\n", max - min);
	return 0;
}
