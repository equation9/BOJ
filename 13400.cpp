/*13400번 Quality of Check Digits(C++11)*/
#include <cstdio>
#define N 10

int OpTb[11][11];

int ssn(int a, int b, int c, int d){
	return OpTb[ OpTb[ OpTb[ OpTb[0][a] ][b] ][c] ][d];
}

int check(int e1, int e2){
	return OpTb[e1][e2];
}

int main()
{
	int i, j, k;
	int res = 0;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &OpTb[i][j]);
		}
	}

	int n[6];
	for(k = 0; k < 10000; k++){
		bool _flag = false;
		n[0] = k/1000;
		n[1] = (k%1000)/100;
		n[2] = (k%100)/10;
		n[3] = k%10;
		n[4] = ssn(n[0], n[1], n[2], n[3]);
	//	printf("\n[%d]", n[0]*10000+n[1]*1000+n[2]*100+n[3]*10+n[4]);//debug
		
		int e1, e2;
		//1
		for(j = 0; j < 5; j++){
			for(i = 0; i < N; i++){
				if(n[j] == i)continue;
				e2 = n[4];

				if(j == 0) e1 = ssn(i, n[1], n[2], n[3]);
				else if(j == 1) e1 = ssn(n[0], i, n[2], n[3]);
				else if(j == 2) e1 = ssn(n[0], n[1], i, n[3]);
				else if(j == 3) e1 = ssn(n[0], n[1], n[2], i);
				else {
					e1 = n[4];
					e2 = i;
				}
				//printf("%d ", e);

				if(!check(e1, e2)){
					//printf("j=%d, i=%d /  %d true\n",j, i, e1);//debug
					_flag = true;
					break;
				}
			}
			if(_flag) break;
		}

		//2
		for(i = 0; i < 4; i++){
			
			if(n[i] == n[i+1]) continue;
			
			//printf("\n[%d]", n[0]*10000+n[1]*1000+n[2]*100+n[3]*10+n[4]);//debug
			int tmp = n[i];
			n[i] = n[i+1];
			n[i+1] = tmp;
			

			if(!check(ssn(n[0], n[1], n[2], n[3]), n[4])){
				_flag = true;
			//	printf(" = [%d] true\n", n[0]*10000+n[1]*1000+n[2]*100+n[3]*10+n[4]);//debug
			}
			
			tmp = n[i];
			n[i] = n[i+1];
			n[i+1] = tmp;
			if(_flag) break;
		}
		if(_flag)
			res++;
	}
	printf("%d\n", res);
	return 0;
}
