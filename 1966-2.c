/*1966번 프린터 큐(C)*/
/*user after free 주의*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node{
	int idx;
	int priority;
	struct _node * next;
}NODE;

static size_t size;
NODE * front; //pop
NODE * back; //push

void push(int id, int prior){
	NODE * new = (NODE * )malloc(sizeof(NODE));
	new->idx = id;
	new->priority = prior;
	
	if(!size){
		front = new;
		back = new;
	}
	else
	{
		if(size == 1)
			front->next = new;
		back->next = new;
		back = new;
	}
	size++;
}

int search_prio()
{
	int cnt = 0;
	NODE * now = front;
	while(now != NULL)
	{
		if(front->priority < now->priority)
			cnt++;
		now = now->next;
	}
	return cnt;
}

void move_back(){
	NODE * now = front;
	front = front->next;
	now->next = NULL;
	back->next = now;
	back = now;
	return;
}

int main(){
	NODE * now;
	int T, N, M, i, tmp, cnt;
	scanf("%d", &T);
	while(T--){
		front = back = NULL;
		size = cnt = 0;

		scanf("%d %d", &N, &M);
		for(i = 0 ; i < N ; i++)
		{
			scanf("%d", &tmp);
			push(i, tmp);
		}

		if(N == 1)
		{
			printf("1\n");
			continue;
		}
		while(1)
		{
			if(search_prio())
			{
				move_back();
			}
			else
			{
				cnt++;
				if(front->idx == M)
					break;
				front = front->next;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
