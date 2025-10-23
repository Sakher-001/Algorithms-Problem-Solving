#include <iostream>
using namespace std;

struct DateInfo {
	short Day;
	short Month;
	short Year;
};

struct Period {
	DateInfo PeriodStart;
	DateInfo PeriodEnd;
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

Period ReadPeriodDate() {
	Period PeriodDate;
	cout << "\nEnter Start Date : " << endl;
	PeriodDate.PeriodStart = ReadFullDateData();
	cout << "\nEnter End Date : " << endl;
	PeriodDate.PeriodEnd = ReadFullDateData();
	return PeriodDate;
};

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

bool CheckPeriodOverLab(Period Period_1, Period Period_2) {
	return !(IsDate1BeforeDate2(Period_1.PeriodEnd, Period_2.PeriodStart) || IsDate1BeforeDate2(Period_2.PeriodEnd, Period_1.PeriodStart));
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

int CounterIncludedDays(Period Period_1 , bool EndDay = false) {
	int Counter = 0;
	while (IsDate1BeforeDate2(Period_1.PeriodStart, Period_1.PeriodEnd)) {
		Period_1.PeriodStart = IncreaseDayByOne(Period_1.PeriodStart);
		Counter++;
	};
	return EndDay ? ++Counter : Counter;
};

int main() {
	cout << "\nEnter Period 1 : \n";
	Period Period_1 = ReadPeriodDate();
	cout << "Period Length Is : " << CounterIncludedDays(Period_1) << endl;
	cout << "Period Length (Included End Day) : " << CounterIncludedDays(Period_1 , true);
}