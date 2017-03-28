/*6996번 애너그램(C++11)*/
#include <cstdio>
#include <cstring>
#include <algorithm>

bool _FLAG;

int main()
{
	char A[101], B[101], sort_a[101], sort_b[101];
	int T, len, i;
	scanf("%d", &T);
	while(T--)
	{
		_FLAG = true;
		scanf("%s %s", A, B);
		len = strlen(A);
		if(len != strlen(B))
		{
			_FLAG = false;
		}
		else
		{
			strncpy(sort_a, A, 101);
			strncpy(sort_b, B, 101);
			std::sort(sort_a, sort_a+len);
			std::sort(sort_b, sort_b+len);
			for(i = 0 ; i < len ; i++)
			{
				if(sort_a[i] != sort_b[i])
				{
					_FLAG = false;
					break;
				}
			}
		}
		printf("%s & %s are%sanagrams.\n", A, B, _FLAG ? " " : " NOT ");
	}
	return 0;
}
