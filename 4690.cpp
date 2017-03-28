/*4690번 완전 세제곱(C++11)*/
#include <cstdio>
int main()
{
	int A, B, C, D;
	int i, j, k, l;
	for(i = 6 ; i <= 100 ; i++)
	{
		A = i*i*i;
		for(j = 2 ; j < i ; j++)
		{
			B = j*j*j;
			for(k = j ; k < i ; k++)
			{
				C = k*k*k;
				for(l = k ; l < i ; l++)
				{
					D = l*l*l;
					if(!(A-B-C-D))
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
					}
				}
			}
		}
	}
	return 0;
}
