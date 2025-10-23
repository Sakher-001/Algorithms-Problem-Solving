#include <iostream>
#include <string>

using namespace std;

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

short CalculateDayOfYear(short Year , short Month , short Day) {
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;
	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string CurrentDayOfDate(short DayOrder) {
	string arr[7] = {"Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat"};
	return arr[DayOrder];
}

void PrintDate(short Year , short Month , short Day , short Num) {
	cout << "Date Is : " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order Is : " << Num << endl;
	cout << "Day Name : " << CurrentDayOfDate(Num);
}

int main() {
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DayOrder = CalculateDayOfYear(Year, Month, Day);
	PrintDate(Year, Month, Day, DayOrder);
}