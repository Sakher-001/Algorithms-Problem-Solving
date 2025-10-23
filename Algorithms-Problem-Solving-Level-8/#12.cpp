#include <iostream>
using namespace std;

struct DateInfo {
	short Year; 
	short Month;
	short Day;
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

short ReadAddDay() {
	short Add;
	cout << "How Many Days You Want To Add : ";
	cin >> Add;
	return Add;
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

DateInfo AddDaysToDate(DateInfo Date, int DaysToAdd) {
	Date.Day += DaysToAdd;

	while (true) {
		short MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > MonthDays) {
			Date.Day -= MonthDays;
			Date.Month++;
			if (Date.Month > 12) {
				Date.Month = 1;
				Date.Year++;
			}
		}
		else {
			break;
		}
	}
	return Date;
}

int main()
{
	Date DateInfo;
	DateInfo.Day = ReadDay();
	DateInfo.Month = ReadMonth();
	DateInfo.Year = ReadYear();
	int DayAdd = ReadAddDay();
	DateInfo =  AddDaysToDate(DateInfo, DayAdd);
	cout << "New Date is: "
		<< DateInfo.Day << "/" << DateInfo.Month << "/" << DateInfo.Year << endl;
}
