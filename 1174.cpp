/*1174번 줄어드는 숫자(C++11)*/
/*하나씩 숫자 문자열을 만들어서 N번째 수를 출력*/
#include <vector>
#include <cstdio>
#include <string>

std::string num[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
std::vector<std::string> Res;

void Make(std::vector<std::string>& res, std::string nn, int d, int dig, int Tdig)
{
	int i;
	if(dig >= Tdig)
	{
		res.push_back(nn);
		return;
	}
	for(i = 0 ; i < d ; i++)
	{
		Make(res, nn+num[i], i, dig+1, Tdig);
	}
}

int main()
{
	int N, cnt, i, j, loop;
	scanf("%d", &N);
	if(N > 1023)
	{
		printf("-1\n");
		return 0;
	}
	for(loop = 0; loop <= N ; loop++)
	{
		for(i = 1 ; i <= 10 ; i++)
		{
			std::vector<std::string> V;
			Make(V, "", 10, 0, i);
			for(j = 0 ; j < V.size() ; j++)
				Res.push_back(V[j]);
			loop += V.size();
		}
	}
	printf("%s\n", Res[N-1].c_str());
	return 0;
}
