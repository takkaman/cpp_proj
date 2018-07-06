#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main()
{
	struct tm base, now;
	struct tm *p, *q;   //tm结构指针
	time_t t, diff_t;  //声明time_t类型变量
	int day, hour, min, sec;
	int tmp;
	char str[1];
	time(&t);      //获取系统日期和时间
	localtime_s(&now, &t);
	printf("%d %d %d\n", now.tm_year, now.tm_mon, now.tm_mday);

	base.tm_year = 117;
	base.tm_mon = 4;
	base.tm_mday = 17;
	base.tm_hour = 18;
	base.tm_min = 0;
	base.tm_sec = 0;

	//now.tm_year += 1900;
	//now.tm_mon += 1;
	diff_t = mktime(&now) - mktime(&base);
	//sprintf_s(str, "%d", 6);
	printf("%d", diff_t);
	//printf("Year: %d, month: %d, day: %d\n", base.tm_year, base.tm_mon, base.tm_mday);
	//printf("Year: %d, month: %d, day: %d\n", now.tm_year, now.tm_mon, now.tm_mday);

	//diff_t = mktime(&now) - mktime(&base);
	//day = diff_t / 86400;
	//hour = diff_t % 86400 / 3600;
	//min = diff_t % 86400 % 3600 / 60;
	//sec = diff_t % 86400 % 3600 % 60;
	//printf("Now: %d\n", mktime(&now));
	//printf("Base: %d\n", mktime(&base));
	//printf("day: %d, hour: %d, min: %d, sec: %d", day, hour, min, sec);
	//printf("now: %d, base: %d", now_t, base_t);
	//printf("Time diff: %d", difftime(now_t, base_t));
	system("pause");
	return 0;
}