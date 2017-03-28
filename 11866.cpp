/*11866번 조세퍼스 문제 0(C++)*/
#include <cstdio>

struct Circle{
	int num;
	Circle * next;
	Circle * prev;
};
Circle * Head;
Circle * Tail;
int size;

void Kill(int M)
{	
	int i;
	Circle * to_kill, * now = Head;
	while(size--)
	{
		for(i = 0 ; i< M-1 ;i++)
		{
			now = now->next;
		}
		to_kill = now;
		now->prev->next = now->next;
		now->next->prev = now->prev;
		now = now->next;

		printf("%d", to_kill->num);
		delete to_kill;
		if(size)
			printf(", ");
	}
	return ;
}

void init(int N)
{
	Circle * tmp, *now=NULL;
	int i;
	for(i = 1 ; i <= N ; i++)
	{
		tmp = new Circle;
		tmp->num = i;
		if(Head == NULL){
			Head = tmp;
		}
		if(now != NULL){
			now->next = tmp;
			tmp->prev = now;
		}
		now = tmp;
	}
	Tail = tmp;
	Tail->next = Head;
	Head->prev = Tail;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	init(N);
	size = N;
	printf("<");
	Kill(M);
	printf(">\n");
	return 0;
}
