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

DateInfo DecreaseDayByOne(DateInfo Date) {
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Day = 31;
			Date.Month = 12;
			Date.Year--;
		}
		else {
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Month , Date.Year);
		}
	}
	else {
		Date.Day--;
	}
	return Date;
}
DateInfo DecreaseDateByXDays(int DaysToAdd, DateInfo Date) {
	for (int i = 1; i <= DaysToAdd; i++)
	{
		Date = DecreaseDayByOne(Date);
	}
	return Date;
}
DateInfo DecreaseDateByOneWeek(DateInfo Date) {
	for (int i = 1; i <= 7; i++) {
		Date = DecreaseDayByOne(Date);
	}
	return Date;
}
DateInfo DecreaseDateByXWeek(int WeeksToAdd, DateInfo Date) {
	for (int i = 1; i <= WeeksToAdd; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}
DateInfo DecreaseDateByOneMonth(DateInfo Date) {
	if (CheckLastMonth(Date))
	{
		Date.Month = 1;
		Date.Year++;
	}
	else {
		Date.Month--;
	}
	return Date;
}
DateInfo DecreaseDateByXMonth(int MonthsToAdd, DateInfo Date) {
	for (int i = 1; i <= MonthsToAdd; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}
DateInfo DecreaseDateByOneYear(DateInfo Date) {
	Date.Year--;
	return Date;
}
DateInfo DecreaseDateByXYears(int YearsToAdd, DateInfo Date) {
	for (int i = 1; i <= YearsToAdd; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
DateInfo DecreaseDateByXYearsFaster(int YearsToAdd, DateInfo Date) {
	Date.Year -= YearsToAdd;
	return Date;
}
DateInfo DecreaseDateByOneDecade(DateInfo Date) {
	for (int i = 1; i <= 10; i++) {
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
DateInfo DecreaseDateByXDecades(int DecadesToAdd, DateInfo Date) {
	for (int i = 1; i <= DecadesToAdd; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}
DateInfo DecreaseDateByXDecadesFaster(int DecadesToAdd, DateInfo Date) {
	Date.Year -= DecadesToAdd * 10;
	return Date;
}
DateInfo DecreaseDateByOneCentury(DateInfo Date) {
	for (int i = 1; i <= 10; i++) {
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}
DateInfo DecreaseDateByOneMilliennium(DateInfo Date) {
	for (int i = 1; i <= 100; i++) {
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}
int main() {
	DateInfo Date = ReadFullDate();
	cout << "\n\nDate After : \n";
	Date = DecreaseDayByOne(Date);
	cout << "\n01 - Date After Decrease One Day : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXDays(10, Date);
	cout << "\n02 - Date After Decrease 10 Days : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneWeek(Date);
	cout << "\n03 - Date After Decrease One Week : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXWeek(10, Date);
	cout << "\n04 - Date After Decrease 10 Week : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneMonth(Date);
	cout << "\n05 - Date After Decrease One Month : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXMonth(5, Date);
	cout << "\n06 - Date After Decrease 5 Months : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneYear(Date);
	cout << "\n07 - Date After Decrease One Year : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXYears(10, Date);
	cout << "\n08 - Date After Decrease 10 Year : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXYearsFaster(10, Date);
	cout << "\n09 - Date After Decrease 10 Year (Faster Method): " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneDecade(Date);
	cout << "\n10 - Date After Decrease One Decades : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXDecades(10, Date);
	cout << "\n11 - Date After Decrease 10 Decades : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXDecadesFaster(10, Date);
	cout << "\n12 - Date After Decrease 10 Decades (Faster Method): " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneCentury(Date);
	cout << "\n13 - Date After Decrease One Century : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneMilliennium(Date);
	cout << "\n14 - Date After Decrease One Milliennium : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}