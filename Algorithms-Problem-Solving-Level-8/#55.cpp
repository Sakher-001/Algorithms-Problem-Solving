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
short ReadVactionDays() {
	short DaysNum;
	cout << "Please Enter a Vaction Days : ";
	cin >> DaysNum;
	return DaysNum;
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


short CalculateDayOfYear(DateInfo Date) {
	short a = (14 - Date.Month) / 12;
	short y = Date.Year - a;
	short m = Date.Month + 12 * a - 2;
	short d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string CurrentDayOfDate(short DayOrder) {
	string arr[7] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };
	return arr[DayOrder];
}

bool IsWeekEnd(DateInfo Date) {
	return (CalculateDayOfYear(Date) == 5) || (CalculateDayOfYear(Date) == 6);
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

DateInfo DateAfterVaction(DateInfo VactionSt , short VactionDays)  {
	for (int i = 1; i <= VactionDays;) {
		if (!IsWeekEnd(VactionSt))
		{
			i++;
		}
		VactionSt = IncreaseDayByOne(VactionSt);
	}
	return VactionSt;
}

void PrintDateAfterVaction(DateInfo NewDate) {
	string DayName = CurrentDayOfDate(CalculateDayOfYear(NewDate));
	cout << "Return Date : " << DayName << " , " << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year;
}

int main()
{
	cout << "Vaction Start : \n";
	DateInfo VactionSt = ReadFullDateData();
	short VactionDays = ReadVactionDays();
	DateInfo ReturnDate = DateAfterVaction(VactionSt, VactionDays);
	PrintDateAfterVaction(ReturnDate);
}