/*15355번 Programiranje(C++11)*/
#include <cstdio>
#include <cstring>
#include <algorithm>

char str[50001];
int Q;
int A, B, C, D;
int alph1[27], alph2[27];
bool _flag;

int main()
{
	int i;
	scanf("%s %d", str, &Q);
	while(Q--)
	{
		scanf("%d %d %d %d", &A, &B, &C, &D);
		if((B-A)!=(D-C)){
			printf("NE\n");
			continue;
		}
		memset(alph1, 0, sizeof(alph1));
		memset(alph2, 0, sizeof(alph2));
		_flag = true;
		
		for(i = A-1; i < B; i++)
			alph1[str[i]-'a']++;
		for(i = C-1; i < D; i++){
			int c = str[i]-'a';
			alph2[c]++;
			if(alph2[c] > alph1[c]){
				_flag = false;
				break;
			}
		}
		printf("%s\n", _flag ? "DA":"NE");
	}
	return 0;
}
