/*13719번 Nizin(C++11)*/
/*투포인터?*/
#include <cstdio>

int N;
int s, e;
int res;
long int ssum, esum;
long int arr[1000001];

int main()
{
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%ld", &arr[i]);
	s = 0;
	e = N-1;
	ssum = arr[s];
	esum = arr[e];
	
	while(s < e){
		if(ssum == esum){
			s++;
			e--;
			ssum = arr[s];
			esum = arr[e];
			continue;
		}

		if(ssum < esum){
			s++;
			ssum += arr[s];
		}
		else {
			e--;
			esum += arr[e];
		}
		res++;
	}
	printf("%d\n", res);
	return 0;
}
