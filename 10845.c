/*10845번 큐(C)*/
/*user after free 주의*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node * next;
}NODE;

static size_t size;
NODE * front; //pop
NODE * back; //push

void free_node(){
	NODE * for_free;
	while(front != NULL){
		for_free=front;
		front = front->next;
		free(for_free);
	}
}

void push(int val){
	NODE * new = (NODE * )malloc(sizeof(NODE));
	new->value = val;
	if(!size){
		front = new;
		back = new;
	}
	else{
		back->next = new;
		back = new;
	}
	size++;
}

int pop(){
	int for_pop;
	NODE * for_free = front;
	if(!size)
		for_pop=-1;
	else{
		for_pop = front->value;
		if(size == 1){
			back = NULL;
			front = NULL;
		}else{
		front = front->next;
		}
		free(for_free);
		size--;
	}

	return for_pop;
}

int main(){
	int N;
	char order[1024];
	fgets(order, 1024, stdin);
	N = atoi(order);
	while(N--){
		fgets(order, 1024, stdin);
		if(!strncmp("push", order, 4))
		{
			push(atoi(order+5));
		}
		else if(!strncmp("pop", order, 3))
		{
			printf("%d\n", pop());
		}
		else if(!strncmp("size", order, 4))
		{
			printf("%lu\n", size);
		}
		else if(!strncmp("empty", order, 5))
		{
			printf("%d\n", size ? 0 : 1);
		}
		else if(!strncmp("front", order, 5))
		{
			printf("%d\n", front != NULL ? front->value : -1);
		}
		else //back
		{
			printf("%d\n", back != NULL ? back->value : -1);
		}
	}
	free_node();
	return 0;
}
