#include <stdio.h>
#include <math.h>
#define N 10000

static int selfnum[N];

void count_selfnum(int num){
	int sum=num, tmp1, tmp2=num, i;
	for(i = 4 ; i >= 0 ; i--){
		tmp1 = tmp2 / ((int)pow(10.0, (double)i));
		sum += tmp1;
		tmp2 -= tmp1 * ((int)pow(10.0, (double)i));
	}

	if(sum <= N)
		selfnum[sum-1]++;
	return;
}

int main(){
	int i;
	count_selfnum(1);

	for(i = 0 ; i < N ; i++)
		count_selfnum(i+1);

	for(i = 0 ; i < N ; i++){
		if(selfnum[i])
			continue;
		else
			printf("%d\n", i+1);
	}
	return 0;
}
