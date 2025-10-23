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

void PrintVactionInfo(DateInfo VactionSt, DateInfo VactionEnd){
	short CountWeekEnd;
	string VactionStDay = CurrentDayOfDate(CalculateDayOfYear(VactionSt));
	string VactionEndDay = CurrentDayOfDate(CalculateDayOfYear(VactionEnd));
	cout << "\nVaction From : " << VactionStDay << " , " << VactionSt.Day << "/" << VactionSt.Month << "/" << VactionSt.Year << endl;
	cout << "Vaction To : " << VactionEndDay << " , " << VactionEnd.Day << "/" << VactionEnd.Month << "/" << VactionEnd.Year << endl;

}

short CountWeekEndDaysInVaction(DateInfo VactionSt , DateInfo VactionEnd) {
	short CountWeekEndDays = 0;
	while (IsDate1BeforeDate2(VactionSt , VactionEnd)) {
		if (IsWeekEnd(VactionSt))
		{
			CountWeekEndDays++;
		}
		VactionSt = IncreaseDayByOne(VactionSt);
	}
	return CountWeekEndDays;
}

int main()
{
	cout << "Vaction Start : \n";
	DateInfo VactionSt = ReadFullDateData();
	cout << endl << endl << "Vaction End : \n";
	DateInfo VactionEnd = ReadFullDateData();
	PrintVactionInfo(VactionSt, VactionEnd);
	cout << "\nActual Vaction Days Is : " << CountWeekEndDaysInVaction(VactionSt, VactionEnd);
}