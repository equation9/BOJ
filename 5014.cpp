/*5014번 스타트링크(C++11)*/
/* bfs */
#include <cstdio>
#include <queue>
#include <utility>

int F, S, G, U, D;
std::queue<std::pair<int, int> > Q; //current floor, count
bool vst[1000001];

int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	Q.push( {S,0} );
	vst[S] = true;
	while(!Q.empty())
	{
		int now = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();
		if(now == G) return 0 | printf("%d\n", cnt);
		

		if( (now+U <= F) && !vst[now+U] )
		{
			Q.push( {now+U, cnt+1} );
			vst[now+U] = true;
		}
		if( (now-D >= 1) && !vst[now-D] ) 
		{
			Q.push( {now-D, cnt+1} );
			vst[now-D] = true;
		}
	}
	printf("use the stairs\n");
	return 0;
}
