// Leab Year ;
#include <iostream>
#include <string>
using namespace std; 

short ReadYear() {
	short Year;
	cout << "Enter YearTo Check : ";
	cin >> Year;
	return Year;
}
bool IsLeabYear(short Year) {
	if (Year % 400 == 0)
	{
		return true;
	}
	else if (Year % 4 == 0 && Year % 100 != 0 ) {
		return true;
	}
	return false;
}

void PrintLeabYears() {
	short Year = ReadYear();
	if (IsLeabYear(Year))
	{
		cout << " \nYes , This Year [ " << Year << " ] Is Leab Year \n";
	}
	else {
		cout << " \nNo , This Year [ " << Year << " ] Is'nt Leab Year \n";
	}
}

int main()
{
	PrintLeabYears();
}