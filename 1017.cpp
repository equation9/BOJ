/*1017번 소수 쌍(C++11)*/
/*이분 그래프*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

bool nPrime[2001], visited[51];
int Match[51], N, ngo, Numb[51], fOdd; //짝수 홀수
std::vector<int> Link[51];
std::vector<int> num[2]; //짝수 홀수

bool dfs(int a)
{
	std::vector<int>::iterator b;
	if(visited[a]) return false;
	visited[a] = true;
	for(b = Link[a].begin() ; b != Link[a].end() ; b++)
	{
		if(*b == ngo) continue;
		if(Match[*b] == -1 || dfs(Match[*b]))
		{
			Match[a] = *b;
			Match[*b] = a;
			//printf("ngo : %d adj : %d-%d\n", ngo, a, *b);//디버깅
			return true;
		}
	}
	return false;

}

int Matching()
{
	std::vector<int>::iterator a;
	int cnt = 1;
	memset(Match, -1, sizeof(Match));
	for(a = num[fOdd].begin() ; a != num[fOdd].end() ; a++)
	{
		memset(visited, false, sizeof(visited));
		visited[0] = true;
		if(dfs(*a)) cnt++;
	}
	return cnt;
}

int main()
{
	int i, j, n;
	std::vector<int>::iterator a;
	
	/*체*/
	for(i = 2 ; i <= 2000 ; i++)
	{
		if(nPrime[i]) continue;
		for(j = 2*i ; j <= 2000 ; j+=i)
		{
			nPrime[j] = true;
		}
	}
	nPrime[0] = nPrime[1] = true;

	/*입력*/
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &n);
		if(!i) fOdd = n%2;
		Numb[i] = n;
		num[n%2].push_back(i);
	}

	/*소수 = 홀수 = (짝수)+(홀수) (2제외)*/
	if(num[0].size() != num[1].size()) return 0 || printf("-1\n");
	
	/*간선 연결*/
	for(i = 0 ; i < N/2 ; i++)
	{
		//printf("%d : ", num[0][i]);//디버깅
		for(j = 0 ; j < N/2 ; j++)
		{
			if(!nPrime[ Numb[num[0][i]] + Numb[num[1][j]] ])
			{
				Link[num[0][i]].push_back(num[1][j]);
				Link[num[1][j]].push_back(num[0][i]);
				//printf("%d ",num[1][j]); //디버깅
			}
		}
		//printf("\n===\n");//디버깅
	}
	
	/*매칭*/
	for(a = Link[0].begin() ; a != Link[0].end() ; a++)
	{
		ngo = *a;
		n = Matching();
		//printf("n: %d\n", n); //디버깅
		if(n == N/2) Link[50].push_back(Numb[*a]);
	}
	/*출력*/

	if(!Link[50].size()) return 0 || printf("-1\n");
	std::sort(Link[50].begin(), Link[50].end());
	for(a = Link[50].begin() ; a != Link[50].end() ; a++)
		printf("%d ", *a);
	printf("\n");
	return 0;
}
