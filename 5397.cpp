/*5897번 키로거(C++11)*/
#include <cstdio>
#include <cstring>
#include <stack>


typedef struct _linked_list
{
	char SN;
	_linked_list * prev;
	_linked_list * next;
}LL;
LL top, bot;
LL * Top;
LL * Bottom;
LL * now;

void push(char c)
{
	LL * Node = new LL;
	Node->SN = c;
	Node->prev = now;
	Node->next = now->next;
	now->next->prev = Node;
	now->next = Node;
	now = Node;
	return;
}

void pop()
{
	if(now == Top)
		return;

	if(Bottom->prev == now)
		Bottom->prev = now->prev;

	LL * for_free = now;
	now->prev->next = now->next;
	now->next->prev = now->prev;
	now = now->prev;
	delete for_free;
}

void move_cursor_left() //down
{
	if(now == Top)
		return;
	now = now->prev;
	return;
}

void move_cursor_right() //up
{
	if(now == Bottom->prev)
		return;	
	now = now->next;
	return;
}

int main()
{
	int T, i;
	char Input[1000001];
	scanf("%d", &T);
	LL * for_free;
	top.prev = NULL;
	bot.next = NULL;
	Top = &top;
	Bottom = &bot;
	while(T--)
	{
		scanf("%s", Input);
		now = Top;
		Top->next = Bottom;
		Bottom->prev = Top;

		for(i = 0 ; i < strlen(Input) ; i++)
		{
			switch(Input[i])
			{
				case '<':
					move_cursor_left();
					break;
				case '>':
					move_cursor_right();
					break;
				case '-':
					pop();
					break;
				default :
					push(Input[i]);
					break;
			}
		}
		now = Top->next;
		while(now != Bottom)
		{
			for_free = now;
			now = now->next;
			printf("%c", for_free->SN);
			delete for_free;
		}
		printf("\n");
	}
	return 0;
}
