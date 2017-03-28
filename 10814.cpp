/*10814번 나이순 정렬(C++11)*/
/*STL*/
#include <cstdio>
#include <algorithm>

struct PEOPLE
{
	int Age, Num;
	char Name[101];
	bool operator < (const PEOPLE &B)
	{
		if(this->Age == B.Age)
			return this->Num < B.Num;
		else
			return this->Age < B.Age;
	}
};

int main()
{
	int N, i;
	PEOPLE user[100000];
	scanf("%d", &N);
	
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d %s", &user[i].Age, user[i].Name);
		user[i].Num = i;
	}
	std::sort(user, user+N);
	for(i = 0 ; i < N ; i++)
	{
		printf("%d %s\n", user[i].Age, user[i].Name);
	}
	return 0;
}
