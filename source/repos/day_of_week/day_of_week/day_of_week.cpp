// day_of_week.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "map"
using namespace std;

// extern int MONTH_DAYS_REMAIN[12] = { 334, 306, 275, 245, 214, 184, 153, 122, 92, 61, 31, 0 };
extern int MONTH_DAYS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
extern string WEEK_DAYS[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

struct Date
{
	int day;
	string month;
	int year;
	string week_day;
};

bool IsLeapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) return true;
	return false;
}

int CalcYearDays(int start, int end) {
	int days=0;
	for (int i = 1; i <= end - start-1; i++) {
		if (IsLeapYear(start + i)) {
			days += 366;
		}
		else {
			days += 365;
		}
	}
	// cout << "year days: " << days << endl;
	return days;
}

int MonthToInt(string month) {
	if (month == "January") return 1;
	if (month == "February") return 2;
	if (month == "March") return 3;
	if (month == "April") return 4;
	if (month == "May") return 5;
	if (month == "June") return 6;
	if (month == "July") return 7;
	if (month == "August") return 8;
	if (month == "September") return 9;
	if (month == "October") return 10;
	if (month == "November") return 11;
	if (month == "December") return 12;
	return 0;
}

int CountRemainingYearDays(Date input) {
	int month_num, days=0;
	month_num = MonthToInt(input.month);
	for (int i = month_num; i < 12; i++) {
		days += MONTH_DAYS[i-1];
	}
	if (IsLeapYear(input.year) && month_num == 1) {	
		days += MONTH_DAYS[month_num - 1] - input.day;
		days += 1;
	} else if (IsLeapYear(input.year) && month_num == 2) {
		days = MONTH_DAYS[month_num - 1] + 1 - input.day;
	}
	else {
		days += MONTH_DAYS[month_num - 1] - input.day;
	}
	// cout << "remaining days: " << days << endl;
	return days;
}

int CountExtraYearDays(Date input) {
	int month_num, days = 0;
	month_num = MonthToInt(input.month);
	for (int i = 1; i < month_num; i++) {
		days += MONTH_DAYS[i - 1];
	}
	if (IsLeapYear(input.year) && month_num >= 3) {
		days += 1;
	}
	days += input.day;
	// cout << "extra days: " << days << endl;
	return days;
}

int CountExtraMonthDays(Date input) {
	return input.day;
}

int CountRemainingMonthDays(Date input) {
	if (MonthToInt(input.month) == 2 && IsLeapYear(input.year)) {
		return MONTH_DAYS[MonthToInt(input.month) - 1] + 1 - input.day;
	}
	else {
		return MONTH_DAYS[MonthToInt(input.month) - 1] - input.day;
	}
}

int CountMonthDays(string start_month, string end_month, int year) {
	int days = 0;
	int start = MonthToInt(start_month), end = MonthToInt(end_month);
	for (int i = start + 1; i < end - start - 1; i++) {
		if (i == 2 && IsLeapYear(year)) days += 1;
		days += MONTH_DAYS[i - 1];
	}
	// cout << "month days: " << days << endl;
	return days;
}

string CalcWeekDay(Date input) {
	Date golden = { 9, "October", 2001, "Tuesday" };
	int start_year, end_year, delta;
	int year_days = 0;
	string week_day;
	if (golden.year > input.year) { // not same year
		year_days += CountRemainingYearDays(input);
		year_days += CalcYearDays(input.year, golden.year);
		year_days += CountExtraYearDays(golden);
		week_day = WEEK_DAYS[(-(year_days % 7) + 7 + 1) % 7];
	}
	else if (golden.year < input.year) { // not same year
		year_days += CountRemainingYearDays(golden);
		year_days += CalcYearDays(golden.year, input.year);
		year_days += CountExtraYearDays(input);
		week_day = WEEK_DAYS[((year_days % 7) + 1) % 7];
	}
	else {  // same year
		if (MonthToInt(golden.month) > MonthToInt(input.month)) { // not same month
			year_days += CountRemainingMonthDays(input);
			year_days += CountMonthDays(input.month, golden.month, golden.year);
			year_days += CountExtraMonthDays(golden);
			week_day = WEEK_DAYS[(-(year_days % 7) + 7 + 1) % 7];
		}
		else if (MonthToInt(golden.month) < MonthToInt(input.month)) { // not same month
			year_days += CountRemainingMonthDays(golden);
			year_days += CountMonthDays(golden.month, input.month, golden.year);
			year_days += CountExtraMonthDays(input);
			week_day = WEEK_DAYS[((year_days % 7) + 1) % 7];
		}
		else { // same month
			if (golden.day >= input.day) {
				week_day = WEEK_DAYS[((-(input.day-golden.day) % 7) + 7 + 1) % 7];
			}
			else {
				week_day = WEEK_DAYS[(((input.day-golden.day) % 7) + 1) % 7];
			}
		}
	}
	// cout << "days: " << year_days << endl;

	return week_day;
}

int main()
{
	int day, year;
	string month;
	//cout << IsLeapYear(2400) << endl;
	while (cin >> day >> month >> year) {
		Date input = { day, month, year };
		cout << CalcWeekDay(input) << endl;
	}
    return 0;
}

