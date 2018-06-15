/*10699번 오늘 날짜(C++11)*/
#include <cstdio>
#include <ctime>
using namespace std;

int main()
{
	char buf[20];
	time_t t;
	tm * time_info;

	time(&t);
	time_info = localtime(&t);
	time_info->tm_hour += 9;
	if(time_info->tm_hour > 23){
		time_info->tm_mday++;
		time_info->tm_hour %= 24;
	}
	strftime(buf, 20, "%Y-%m-%d", time_info);
	printf("%s\n", buf);
	return 0;
}
