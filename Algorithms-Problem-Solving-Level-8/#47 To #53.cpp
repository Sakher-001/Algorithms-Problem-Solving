#pragma warning(disable:4996)
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct DateInfo {
	short Day;
	short Month;
	short Year;
};

DateInfo GetSystemDate() {
	DateInfo DynamicDate;
	time_t t = time(0);
	tm* DateNow = localtime(&t);
	DynamicDate.Year = DateNow->tm_year + 1900;
	DynamicDate.Month = DateNow->tm_mon + 1;
	DynamicDate.Day = DateNow->tm_mday;
	return DynamicDate;
}


bool IsLeabYear(short Year) {
	return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInMonth(short Month, short Year) {
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	// First Method
// 	return Month == 2 ? (IsLeabYear(Year) ? 29 : 28) : (Month == 1 || Month == 3 || Month == 5 || Month == 7 ||	Month == 8 || Month == 10 ||Month == 12) ? 31 : 30;


// Second Method 
	short DaysInMonth[12] = { 31, IsLeabYear(Year) ? 29 : 28 , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return DaysInMonth[Month - 1];
}

string CurrentMonthOfDate(short MonthOrder) {
	string arr[13] = {"" , "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sept" , "Oct" , "Nov"  , "Dec"};
	return arr[MonthOrder];
}

short CalculateDayOfYear(short Year, short Month, short Day) {
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;
	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

short CalculateDayOfYear(DateInfo Date) {
	short a = (14 - Date.Month) / 12;
	short y = Date.Year - a;
	short m = Date.Month + 12 * a - 2;
	short d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string CurrentDayOfDate(short DayOrder) {
	string arr[7] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };
	return arr[DayOrder];
}

void PrintDayInfo(DateInfo Date) {
	short DayOrder = CalculateDayOfYear(Date.Year, Date.Month, Date.Day);
	cout << "Today Is : " << CurrentDayOfDate(DayOrder) << "\t" << Date.Day << "/" << Date.Month << "/" << Date.Year;
}

bool CheckLastDay(DateInfo Date) {
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool CheckLastMonth(DateInfo Date) {
	return (Date.Month == 12);
}

bool IsEndWeek(DateInfo Date) { // End Week Is Saturday ;
	return (CalculateDayOfYear(Date) == 6);
}

bool IsWeekEnd(DateInfo Date) {
	return (CalculateDayOfYear(Date) == 5) || (CalculateDayOfYear(Date) == 6);
}

bool IsBusnissDay(DateInfo Date) {
	return !IsWeekEnd;
}

void PrintAllStatues(DateInfo Date) {
	cout << "Is End Of Week ? : \n";
	if (IsEndWeek(Date))
	{
		cout << "Yes it's end of week\n\n";
	}
	else {
		cout << "No it isn't end of week\n\n";
	}

	cout << "Is  WeekEnd ? : \n";

	if (IsWeekEnd(Date))
	{
		cout << "Yes it's WeekEnd\n\n";
	}
	else {
		cout << "No it isn't WeekEnd\n\n";
	}
	cout << "Is Busniss Day? : \n";

	if (IsBusnissDay(Date))
	{
		cout << "Yes it's Busniss Day\n\n";
	}
	else {
		cout << "No it isn't Busniss Day\n\n";
	}
}

short CalculateDaysUntillEndOfWeek(DateInfo Date) {

	return 6 - CalculateDayOfYear(Date);
}

short CalculateDaysUntillEndOfMonth(DateInfo Date) {
	short Count = 0;
	while (Count != NumberOfDaysInMonth(Date.Month , Date.Year)) {
		Count++;
	}
	return Count - Date.Day;
}

DateInfo IncreaseDayByOne(DateInfo Date) {
	if (CheckLastDay(Date) && CheckLastMonth(Date))
	{
		Date.Day = 1;
		Date.Month = 1;
		Date.Year++;
	}
	else if (CheckLastDay(Date)) {
		Date.Day = 1;
		Date.Month++;
	}
	else {
		Date.Day++;
	}
	return Date;
}

short CalculateDaysUntillEndOfYear(DateInfo Date) {
	short Count = 0;
	while (!(CheckLastDay(Date) && CheckLastMonth(Date))) {
		Date = IncreaseDayByOne(Date);
		Count++;
	}
	return Count;
 }
int main() {
	DateInfo DateNow = GetSystemDate();
	PrintDayInfo(DateNow);
	cout << endl << endl ; 
	PrintAllStatues(DateNow);
	cout << "Days untill end of week is  : " << CalculateDaysUntillEndOfWeek(DateNow) << " Day(s)\n";
	cout << "Days untill end of month is : " << CalculateDaysUntillEndOfMonth(DateNow) << " Day(s)\n";
	cout << "Days untill end of Year is  : " << CalculateDaysUntillEndOfYear(DateNow) << " Day(s)\n";

}