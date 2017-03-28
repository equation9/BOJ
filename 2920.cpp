/*2920번 음계(C++)*/
#include <cstdio>
#include <vector>

int main(){
	std::vector<int> melo;
	int tmp, cnt=0, i;
	melo.push_back(0);
	for(i = 0 ; i < 8 ; i++){
		scanf("%d", &tmp);
		if(tmp < melo.back())
			cnt--;
		else // tmp > melo.back()
			cnt++;
		melo.push_back(tmp);
	}
	switch(cnt){
		case 8 : printf("ascending\n");
				 break;
		case -6 : printf("descending\n");
				 break;
		default : printf("mixed\n");
				 break;
	}
	return 0;
}
