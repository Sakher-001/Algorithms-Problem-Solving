#include <iostream>
using namespace std;


struct DateInfo {
	short Day;
	short Month;
	short Year;
};

short ReadYear() {
	short Year;
	cout << "Please Enter a Year : ";
	cin >> Year;
	return Year;
}


short ReadMonth() {
	short Month;
	cout << "Please Enter a Month : ";
	cin >> Month;
	return Month;
}

short ReadDay() {
	short Day;
	cout << "Please Enter a Day : ";
	cin >> Day;
	return Day;
}

DateInfo ReadFullDate() {
	DateInfo Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
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



bool CheckLastDay(DateInfo Date) {
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool CheckLastMonth(DateInfo Date) {
	return (Date.Month == 12);
}

DateInfo IncreaseDayByOne(DateInfo Date) {
	if (CheckLastDay(Date))
	{
		if (CheckLastMonth(Date))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else {
			Date.Day = 1; 
			Date.Month++;
		}
	}
	else {
		Date.Day++;
	}
	return Date;
}
DateInfo IncreaseDateByXDays( int DaysToAdd ,  DateInfo Date) {
	for (int i = 1; i <= DaysToAdd; i++)
	{
		Date = IncreaseDayByOne(Date);
	}
	return Date;
}
DateInfo IncreaseDateByOneWeek(DateInfo Date) {
	for (int i = 1; i <= 7; i++) {
		Date = IncreaseDayByOne(Date);
	}
	return Date;
}
DateInfo IncreaseDateByXWeek(int WeeksToAdd, DateInfo Date) {
	for (int i = 1; i <= WeeksToAdd; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}
DateInfo IncreaseDateByOneMonth(DateInfo Date) {
	if (CheckLastMonth(Date))
	{
		Date.Month = 1;
		Date.Year++;
	}
	else {
		Date.Month++;
	}
	return Date;
}
DateInfo IncreaseDateByXMonth(int MonthsToAdd, DateInfo Date) {
	for (int i = 1; i <= MonthsToAdd; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}
DateInfo IncreaseDateByOneYear(DateInfo Date) {
	Date.Year++;
	return Date;
}
DateInfo IncreaseDateByXYears(int YearsToAdd, DateInfo Date) {
	for (int i = 1; i <= YearsToAdd; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}
DateInfo IncreaseDateByXYearsFaster(int YearsToAdd, DateInfo Date) {
	Date.Year += YearsToAdd;
	return Date;
}
DateInfo IncreaseDateByOneDecade(DateInfo Date) {
	for (int i = 1; i <= 10; i++) {
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}
DateInfo IncreaseDateByXDecades(int DecadesToAdd, DateInfo Date) {
	for (int i = 1; i <= DecadesToAdd; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}
DateInfo IncreaseDateByXDecadesFaster(int DecadesToAdd, DateInfo Date) {
	Date.Year += DecadesToAdd * 10;
	return Date;
}
DateInfo IncreaseDateByOneCentury(DateInfo Date) {
	for (int i = 1; i <= 10; i++) {
		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}
DateInfo IncreaseDateByOneMilliennium(DateInfo Date) {
	for (int i = 1; i <= 100; i++) {
		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}
int main() {
	DateInfo Date = ReadFullDate();
	cout << "\n\nDate After : \n";
	Date = IncreaseDayByOne(Date);
	cout << "\n01 - Date After Adding One Day : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXDays(10, Date);
	cout << "\n02 - Date After Adding 10 Days : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneWeek(Date);
	cout << "\n03 - Date After Adding One Week : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXWeek(10, Date);
	cout << "\n04 - Date After Adding 10 Week : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneMonth(Date);
	cout << "\n05 - Date After Adding One Month : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXMonth(5, Date);
	cout << "\n06 - Date After Adding 5 Months : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneYear(Date);
	cout << "\n07 - Date After Adding One Year : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXYears(10 ,Date);
	cout << "\n08 - Date After Adding 10 Year : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXYearsFaster(10, Date);
	cout << "\n09 - Date After Adding 10 Year (Faster Method): " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneDecade(Date);
	cout << "\n10 - Date After Adding One Decades : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXDecades(10, Date);
	cout << "\n11 - Date After Adding 10 Decades : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXDecadesFaster(10, Date);
	cout << "\n12 - Date After Adding 10 Decades (Faster Method): " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneCentury(Date);
	cout << "\n13 - Date After Adding One Century : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneMilliennium(Date);
	cout << "\n14 - Date After Adding One Milliennium : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}