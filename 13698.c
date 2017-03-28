#include <stdio.h>

void swap(int cup[], char order){
	int swp1, swp2, temp;
	switch(order){
		case 'A' :
			swp1 = 0;
			swp2 = 1;
			break;
		case 'B' :
			swp1 = 0;
			swp2 = 2;
			break;
		case 'C' :
			swp1 = 0;
			swp2 = 3;
			break;
		case 'D' :
			swp1 = 1;
			swp2 = 2;
			break;
		case 'E' :
			swp1 = 1;
			swp2 = 3;
			break;
		case 'F' :
			swp1 = 2;
			swp2 = 3;
			break;
	}
	temp = cup[swp1];
	cup[swp1] = cup[swp2];
	cup[swp2] = temp;
	return;
}

int main(){
	char mix[201];
	static int Cup[4], idx, sm, lg;
	Cup[0] = 1;
	Cup[3] = 2;
	fgets(mix, 201, stdin);
	while(mix[idx] != '\n' && mix[idx] != '\0')
		swap(Cup, mix[idx++]);

	for(idx = 0 ; idx < 4 ; idx++){
		if(Cup[idx])
			if(Cup[idx] == 1)
				sm = idx+1;
			else
				lg = idx+1;
	}
	printf("%d\n%d\n", sm, lg);
	return 0;
}
