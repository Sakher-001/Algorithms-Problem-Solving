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

short NumberOfDaysInMonth(short Month , short Year) {
	if (Month < 1 || Month > 12 )
	{
		return 0;
	}
	if (Month == 2)
	{
		return IsLeabYear(Year) ? 29 : 28;
	}
	short arr31Days[7] = { 1 , 3 , 5 ,7 ,8 ,10 , 12 };
	for (int i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month) {
			return 31;
		}
	}
	return 30;
}



short NumberOfHoursInMonth(short Month, short Year) {
	return NumberOfDaysInMonth(Month, Year) * 24;
}
int NumberOfMinutesInMonth(short Month , short Year) {
	return NumberOfHoursInMonth(Month, Year) * 60;
}
int NumberOfSecondsInMonth(short Month, short Year) {
	return NumberOfMinutesInMonth(Month, Year) * 60;
}

void PrintFillYear(short Month , short Year) {
	cout << "Numbers Of days    in Month [ " << Month << " ] is : " << NumberOfDaysInMonth(Month, Year) << endl;
	cout << "Numbers Of Hours   in Month [ " << Month << " ] is : " << NumberOfHoursInMonth(Month, Year) << endl;
	cout << "Numbers Of Minutes in Month [ " << Month << " ] is : " << NumberOfMinutesInMonth(Month, Year) << endl;
	cout << "Numbers Of Seconds in Month [ " << Month << " ] is : " << NumberOfSecondsInMonth(Month, Year) << endl;

}
int main()
{
	int SelectedYear = ReadYear();
	int SelectedMonth = ReadMonth();
	PrintFillYear( SelectedMonth, SelectedYear);
}