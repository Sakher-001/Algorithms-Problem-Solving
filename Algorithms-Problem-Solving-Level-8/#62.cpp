#include <iostream>
using namespace std;

struct DateInfo {
	short Day;
	short Month;
	short Year;
};

DateInfo ReadFullDateData() {
	DateInfo Date;
	cout << "Please Enter A Day : ";
	cin >> Date.Day;
	cout << "Please Enter A Month : ";
	cin >> Date.Month;
	cout << "Please Enter A Year : ";
	cin >> Date.Year;
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

bool IsValidDate(DateInfo Date) {
	if (Date.Month > 12 || Date.Month < 1)
		return false;
	if (Date.Day > NumberOfDaysInMonth(Date.Month , Date.Year) || Date.Day < 1)
		return false;
	return true;
}
void PrintValidateResult(DateInfo Date) {
	if (IsValidDate(Date))
	{
		cout << "Yes , Date is Validate Date\n";
	}
	else {
		cout << "No , Date is a NOT Validate Date\n";
	}
}

int main() {
	DateInfo Date = ReadFullDateData();
	PrintValidateResult(Date);
}