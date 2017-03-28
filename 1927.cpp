/*1927번 최소 힙(C++11)*/
#include <cstdio>
#define ROOT 1

int Heap[100001];
int size;

void H_insert(int val)
{
	int i = ++size;
	while((i != ROOT) && (val < Heap[i/2]))
	{
		Heap[i] = Heap[i/2];
		i /= 2;
	}
	Heap[i] = val;
	return;
}

int H_delete()
{
	int val = Heap[ROOT], parent=1, child=2, end = Heap[size--];
	while(child <= size)
	{
		if((child < size)&&(Heap[child] > Heap[child+1]))
			child++;
		if(end <= Heap[child])
			break;
		Heap[parent] = Heap[child];
		parent = child;
		child *= 2;
	}
	Heap[parent] = end;
	return val;
}

int main()
{
	int N, tmp, i;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &tmp);
		if(!tmp)
		{
			if(!size)
				printf("0\n");
			else
			{
				printf("%d\n", H_delete());
			}
		}
		else
		{
			if(!size)
			{
				Heap[ROOT] = tmp;
				size++;
			}
			else
			{
				H_insert(tmp);
			}
		}
	}
	return 0;
}
