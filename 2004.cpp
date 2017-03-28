/*조합 0의 개수(C++11)*/
#include <cstdio>
long long int n, m, cnt_F[3], cnt_T[3];

int n_facto(int num, int idx)
{
	long long int i, cnf=0, cnt=0;
	for(i = 5 ; i <= num ; i*=5)
	{
		cnf += num/i;
	}
	for(i = 2 ; i <= num ; i*=2)
	{
		cnt += num/i;
	}
	cnt_F[idx] = cnf;
	cnt_T[idx] = cnt;
}

int main()
{
	long long int t, f;
	scanf("%lld %lld", &n, &m);
	n_facto(n, 0);
	n_facto(n - m, 1);
	n_facto(m, 2);
	t = cnt_T[0] - cnt_T[1] - cnt_T[2];
	f = cnt_F[0] - cnt_F[1] - cnt_F[2];
	printf("%lld\n", f < t ? f : t);
	return 0;
}
