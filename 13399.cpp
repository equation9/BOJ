/*13399번 Rearranging a Sequence(C++11)*/
#include <cstdio>
#include <stack>

int N, M;
bool num[200001];
std::stack<int> S;

int main()
{
	int i, a;
	scanf("%d %d", &N, &M);
	for(i = 0 ; i < M; i++){
		scanf("%d", &a);
		S.push(a);
	}
	while(!S.empty()){
		a = S.top();
		S.pop();
		if(num[a]) continue;
		num[a] = true;
		printf("%d\n", a);
	}
	for(i = 1; i<= N; i++){
		if(num[i]) continue;
		printf("%d\n", i);
	}
	return 0;
}
