/*1963번 소수경로(C++11)*/
/*bfs*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

bool Prime[10000], visit[10000];
bool Dist[10000][10000];
std::queue<std::pair<int, int> > q;

int main()
{
	int i, j;
	/*체*/
	std::fill(Prime, Prime+10000, true);
	Prime[0] = false;
	for(i = 2 ; i < 5000 ; i++)
	{
		if(!Prime[i]) continue;
		for(j = i*2 ; j < 10000 ; j += i)
		{
			Prime[j] = false;
		}
	}
	/*초기화*/
	for(i = 1001 ; i < 9999 ; i++)
	{
		if(!Prime[i]) continue;
		int tmp = i%1000;
		for(j = 1000 ; j <= 9000 ; j+=1000){
			if(tmp+j == i || !Prime[tmp+j]) continue;
			//printf("%d-%d\n", tmp+j, i);//debug
			Dist[i][j+tmp] = Dist[j+tmp][i] = true;
		}
		tmp = (i-(i%1000))+i%100;
		for(j = 0 ; j <= 900 ; j+=100){
			if(tmp+j == i || !Prime[tmp+j]) continue;
			//printf("%d-%d\n", tmp+j, i);//debug
			Dist[i][j+tmp] = Dist[j+tmp][i] = true;
		}
		tmp = (i-(i%100))+(i%10);
		for(j = 0 ; j <= 90 ; j+=10){
			if(tmp+j == i || !Prime[tmp+j]) continue;
			//printf("%d-%d\n", tmp+j, i);//debug
			Dist[i][j+tmp] = Dist[j+tmp][i] = true;
		}
		tmp = i-(i%10);
		for(j = 0 ; j <= 9 ; j++){
			if(tmp+j == i || !Prime[tmp+j]) continue;
			//printf("%d-%d\n", tmp+j, i);//debug
			Dist[i][j+tmp] = Dist[j+tmp][i] = true;
		}
	}
	/*bfs*/
	int N, a, b, dist;
	bool _flag;
	scanf("%d", &N);
	while(N--)
	{
		while(!q.empty()) q.pop(); //초기화
		std::fill(visit, visit+10000, false);
		_flag = false;

		scanf("%d %d", &a, &b);
		q.push( {a, 0} );
		visit[a] = true;
		while(!q.empty())
		{
			int now = q.front().first;
			int ndist = q.front().second;
			q.pop();

			//printf("%d-%d : %d\n", now, i, ndist);//debug
			if(now == b)
			{
				_flag = true;
				printf("%d\n", ndist);
				break;
			}
			
			for(i = 1001 ; i < 9999 ; i++)
			{
				if(Dist[now][i] && !visit[i])
				{	
					q.push({i, ndist+1});
					visit[i]= true;
				}
			}
		}
		if(!_flag) printf("Impossible\n");
	}
	return 0;
}
