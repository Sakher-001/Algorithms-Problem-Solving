#include <iostream>
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

int CalculateTotalDaysOfYear(short Day , short Month , short Year) {
	int TotalDays = 0;
	for (int i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	return TotalDays + Day;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	cout << "The Total Days From The beigenning year Is : " << CalculateTotalDaysOfYear(Day, Month, Year);
}
