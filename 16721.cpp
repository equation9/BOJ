/*16721번tructure of Balanced Networks(C++11)*/
#include <cstdio>

int main()
{
	short int n, i, j;
	char rel[5001];
	scanf("%hd", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			scanf(" %c", &rel[j]);
			if(rel[j] == '0') rel[j] = '+';
		}
	scanf("%hd", &n);
	while(n--){
		scanf("%hd%hd", &i, &j);
		if(rel[i] == rel[j])
			printf("+\n");
		else
			printf("-\n");
	}
	return 0;
}
