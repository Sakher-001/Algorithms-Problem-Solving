#include <iostream>

using namespace std;


short ReadYear() {
	short Year;
	cout << "Enter YearTo Check : ";
	cin >> Year;
	return Year;
}


short ReadMonth() {
	short Month;
	cout << "Enter YearTo Check : ";
	cin >> Month;
	return Month;
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
	short DaysInMonth[12] = { 31, IsLeabYear(Year) ? 29  : 28 , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return DaysInMonth[Month - 1];
}



short NumberOfHoursInMonth(short Month, short Year) {
	return NumberOfDaysInMonth(Month, Year) * 24;
}
int NumberOfMinutesInMonth(short Month, short Year) {
	return NumberOfHoursInMonth(Month, Year) * 60;
}
int NumberOfSecondsInMonth(short Month, short Year) {
	return NumberOfMinutesInMonth(Month, Year) * 60;
}

void PrintFillYear(short Month, short Year) {
	cout << "Numbers Of days in Month [ " << Month << " ] is : " << NumberOfDaysInMonth(Month, Year) << endl;
}
int main()
{
	int SelectedYear = ReadYear();
	int SelectedMonth = ReadMonth();
	PrintFillYear(SelectedMonth, SelectedYear);
}