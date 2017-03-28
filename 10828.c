/*10828번 스택*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack{
	int value;
	struct _stack * next;
}STACK;

STACK * Top;
static size_t size;

void push(char * num){
	STACK * new = (STACK * )malloc(sizeof(STACK));
	new->value = atoi(num);
	new->next = Top;
	Top = new;
	size++;
	return;
}

void pop(void){
	if(!size){
		printf("-1\n");
		return;
	}

	STACK * for_pop = Top;
	Top = Top->next;
	printf("%d\n", for_pop->value);
	free(for_pop);
	size--;
	return;
}

int main(){
	char Order[50];
	fgets(Order, 50, stdin);
	int N = atoi(Order);
	STACK * for_free;

	while(N--){
		fgets(Order, 50, stdin);
		
		if(!strncmp(Order, "push", 4)){
			push(Order+5);
		}

		else if(!strncmp(Order, "pop", 3)){
			pop();
		}

		else if(!strncmp(Order, "size", 4)){
			printf("%lu\n", size);
		}

		else if(!strncmp(Order, "empty", 5)){
			if(size)
				printf("0\n");
			else
				printf("1\n");
		}

		else if(!strncmp(Order, "top", 3)){
			if(!size)
				printf("-1\n");
			else
				printf("%d\n", Top->value);
		}
	}

	while(Top != NULL){
		for_free = Top;
		Top = Top->next;
		free(for_free);
	}
	return 0;
}
