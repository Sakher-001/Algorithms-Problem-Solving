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

bool IsDate1BeforeDate2(DateInfo Date1, DateInfo Date2) {
	if (Date1.Year < Date2.Year) {
		return true;
	}
	else if (Date1.Year == Date2.Year) {
		if (Date1.Month < Date2.Month) {
			return true;
		}
		else if (Date1.Month == Date2.Month) {
			if (Date1.Day < Date2.Day) {
				return true;
			}
		}
	}
	return false;
}

bool Is2DatesAreEqual(DateInfo Date1, DateInfo Date2) {
	return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
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
	if (CheckLastDay(Date) && CheckLastMonth(Date))
	{
		Date.Day = 1;
		Date.Month = 1;
		Date.Year++;
	}
	else if (CheckLastDay(Date)) {
		Date.Day = 1;
		Date.Month++;
	}
	else {
		Date.Day++;
	}
	return Date;
}



int CalculateDiffranceBetweenTwoDates(DateInfo Date1, DateInfo Date2, bool IncludeEndDay = false) {
	int Days = 0;
	DateInfo SwapDates;
	short Dir = 1;
	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		SwapDates = Date2;
		Date2 = Date1;
		Date1 = SwapDates;
		Dir = -1;
	}
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Date1 = IncreaseDayByOne(Date1);
		Days++;
	}
	return IncludeEndDay ? (++Days * Dir) : (Days * Dir);
}

int main()
{
	DateInfo Date1 = ReadFullDateData();
	cout << endl << endl;
	DateInfo Date2 = ReadFullDateData();
	cout << "Diffrance Between Two Days : " << CalculateDiffranceBetweenTwoDates(Date1, Date2) << " Day(s)" << endl;
	cout << "Diffrance Between Two Days include End Day : " << CalculateDiffranceBetweenTwoDates(Date1, Date2, true) << " Day(s)" << endl;
}