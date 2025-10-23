#include <iostream>
#include <iomanip>
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

string CurrentMonthOfDate(short MonthOrder) {
	string arr[13] = { "" , "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sept" , "Oct" , "Nov"  , "Dec" };
	return arr[MonthOrder];
}

short CalculateDayOfYear(short Year, short Month, short Day) {
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;
	short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string CurrentDayOfDate(short DayOrder) {
	string arr[7] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };
	return arr[DayOrder];
}

void PrintFillMonth(short Year , short Month) {
	int CurrentDay = CalculateDayOfYear(Year, Month, 1);
	int NumberOfDays = NumberOfDaysInMonth(Month, Year);
	printf("\n_____________________%s_____________________\n\n", CurrentMonthOfDate(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	int i;
	for (i = 0; i < CurrentDay; i++) {
		printf("     ");
	}
	for (int j = 1; j <= NumberOfDays; j++) {
		printf("%5d", j);
		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
}

void PrintClenderForEachYear(short Year) {
	printf("\n_____________________________________________\n\n");
	printf("\n\t\t Calender - %d \n\n" , Year);
	printf("\n_____________________________________________\n\n");
	for (int i = 1; i <= 12; i++) {
		PrintFillMonth(Year , i);
	}
}

int main()
{
	short Year = ReadYear();
	PrintClenderForEachYear(Year);
}