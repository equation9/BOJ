/*2503번 숫자 야구(C++11)*/
#include <cstdio>

int possible[1000];
int stri, ball;

int dupl(int guess)
{
	int a, b, c;
	a = guess/100;
	b = (guess%100)/10;
	c= guess%10;
	if((a==b)||(a==c)||(b==c)||!b||!c)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int dist(int guess, int comp)
{
	char a[4], b[4];
	int cst=0, cba=0, i, j;
	snprintf(a, 4, "%d", guess);
	snprintf(b, 4, "%d", comp);
	for(i = 0 ; i < 3 ; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{
			if(a[i] == b[j])
			{
				if(i == j)
					cst++;
				else
					cba++;
			}
		}
	}

	if((cst == stri) && (cba == ball))
	{
		return 1;
	}
	else
	{
		//printf("%s %s %d %d\n", a, b, cst, cba);
		return 0;
	}
}

void find_poss(int guess)
{
	int i;
	for(i = 123 ; i <= 987 ; i++)
	{
		if(!possible[i])
			continue;
		if(!dist(guess, i))
		{
			possible[i] = 0;
		}
	}
	return;
}

int main()
{
	int N, i, guess, cnt=0;
	for(i = 123 ; i <= 987 ; i++)
	{
		if(!dupl(i))
		{
			possible[i] = 1;
		}
	}
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d %d %d", &guess, &stri, &ball);
		//printf("%d %d\n", stri, ball);
		find_poss(guess);
		/*for(i = 123 ; i <= 987 ; i++)
		{
			if(possible[i])
			printf("%d ", i);
		}
		printf("\n\n");*/
	}
	for(i = 123 ; i <= 987 ; i++)
	{
		cnt += possible[i];
	}
	printf("%d\n", cnt);
	return 0;
}
