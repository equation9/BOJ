/*1408번 24(C++11)*/
#include <cstdio>
int main()
{
	int Nh, Nm, Ns, Eh, Em, Es, N, E;
	int H, M, S;
	char tmp;
	scanf("%d%c%d%c%d", &Nh, &tmp, &Nm, &tmp, &Ns);
	scanf("%d%c%d%c%d", &Eh, &tmp, &Em, &tmp, &Es);
	
	H = Eh - Nh;
	if(Nh > Eh)
	{
		H += 24;
	}
	M = Em - Nm;
	if(Nm > Em)
	{
		M += 60;
		H--;
	}
	S = Es - Ns;
	if(Ns > Es)
	{
		S += 60;
		if(!M)
		{
			H--;
			M += 60;
		}
		M--;
	}
	if(H < 10)
		printf("0");
	printf("%d:", H);
	if(M < 10)
		printf("0");
	printf("%d:", M);
	if(S < 10)
		printf("0");
	printf("%d\n",S);
	return 0;
}
