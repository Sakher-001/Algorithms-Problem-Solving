#include <iostream>

using namespace std;


short ReadYear() {
	short Year;
	cout << "Enter YearTo Check : ";
	cin >> Year;
	return Year;
}

bool IsLeabYear(short Year) {
	return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInYear(short Year) {
	return IsLeabYear(Year) ? 366 : 365;
}
short NumberOfHoursInYear(short Year) {
	return NumberOfDaysInYear(Year) * 24;
}
int NumberOfMinutesInYear(short Year) {
	return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondsInYear(short Year) {
	return NumberOfMinutesInYear(Year) * 60;
}

void PrintFillYear(short Year) {
	cout << "Numbers Of days    in year [ " << Year << " ] is : " << NumberOfDaysInYear(Year) << endl ;
	cout << "Numbers Of Hours   in year [ " << Year << " ] is : " << NumberOfHoursInYear(Year) << endl;
	cout << "Numbers Of Minutes in year [ " << Year << " ] is : " << NumberOfMinutesInYear(Year) << endl;
	cout << "Numbers Of Seconds in year [ " << Year << " ] is : " << NumberOfSecondsInYear(Year) << endl;

}
int main()
{
	int SelectedYear = ReadYear();
	PrintFillYear(SelectedYear);
}

