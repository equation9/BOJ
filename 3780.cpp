/*3780번 네트워크 연결(C++11)*/
/*unsynced iostream <<<<< cstdio 이것때문에 6번시간초과남*/
#include <cstdio>
#include <cstring>
using namespace std;

int N, T, I, J;
char c;
int server[20001]; //i의 부모서버
int dist[20001];

int getdist(int i, int j){
	int ret = i-j;
	if(ret < 0) ret = -ret;
	return ret % 1000;
}

int findroot(int i){
	if(server[i] == -1) 
		return i;
	int root = findroot(server[i]);
	dist[i] += dist[server[i]];
	return server[i] = root;
}

int main()
{

	scanf("%d",&T);
	while(T--){
		scanf("%d", &N);
		c = ' ';
		memset(server, -1, sizeof(server));
		memset(dist, 0 , sizeof(dist));
		while(c != 'O')
		{
			scanf("%c", &c);
			if(c == 'O') break;
			switch(c)
			{
				case 'E' :
					scanf("%d", &I);
					findroot(I);
					printf("%d\n", dist[I]);
					break;
				case 'I' :
					scanf("%d %d", &I, &J); //I센터 J기업
					if(findroot(I) != findroot(J)){
						server[I] = J;
						dist[I] = getdist(I,J);
					}
					break;
				default :
					break;
			}
		}
	}
	return 0;
}
