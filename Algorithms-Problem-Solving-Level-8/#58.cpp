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

bool CheckPeriodOverLab(Period Period_1 , Period Period_2) {
	return !(IsDate1BeforeDate2(Period_1.PeriodEnd , Period_2.PeriodStart) || IsDate1BeforeDate2(Period_2.PeriodEnd , Period_1.PeriodStart));
}



int main() {
	cout << "\nEnter Period 1 : \n";
	Period Period_1 = ReadPeriodDate();
	cout << "\nEnter Period 2 : \n";
	Period Period_2 = ReadPeriodDate();
	if (CheckPeriodOverLab(Period_1 , Period_2))
		cout << "\n Yes , Period Is OverLab\n";
	else
		cout << "\n No , Period Isn't OverLab \n";
}