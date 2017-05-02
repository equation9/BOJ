/*5639번 이진 검색 트리(C++11)*/
#include <cstdio>

struct Node
{
	int num;
	Node * llink; //작은 수
	Node * rlink; //큰 수 
};

Node * root;
Node * now;

void PostSearch(Node * subr)
{
	if(subr == NULL)
		return;
	PostSearch(subr->llink);
	PostSearch(subr->rlink);
	printf("%d\n", subr->num);
	delete subr;
	return;
}

int main()
{
	int n;
	Node * make;
	while(scanf("%d", &n) != -1)
	{
		if(!root) //루트
		{
			make = new Node;
			make->num = n;
			root = make;
			continue;
		}

		make = new Node;
		make->num = n;

		now = root;
		while(1)
		{
			if(n < now->num)
			{
				if(now->llink == NULL)
				{
					now->llink = make;
					now = now->llink;		
					break;
				}
				now = now->llink;
			}
			else	
			{
				if(now->rlink == NULL)
				{
					now->rlink = make;
					now = now->rlink;
					break;
				}
				now = now->rlink;
			}
		}
	}
	PostSearch(root);
	return 0;
}
