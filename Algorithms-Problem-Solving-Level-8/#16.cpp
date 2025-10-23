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
	if (CheckLastDay(Date) && CheckLastMonth(Date) )
	{
		Date.Day = 1;
		Date.Month = 1;
		Date.Year++;
	}
	else if(CheckLastDay(Date)){
		Date.Day = 1;
		Date.Month++;
	}
	else {
		Date.Day++;
	}
	return Date;
}

int main() {
	DateInfo Date = ReadFullDate();
	Date = IncreaseDayByOne(Date);
	cout << "Date After Adding One Day : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}