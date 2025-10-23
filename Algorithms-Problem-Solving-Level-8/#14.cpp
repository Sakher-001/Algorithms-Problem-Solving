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


int main()
{
	DateInfo Date1 = ReadFullDateData();
	cout << endl << endl;
	DateInfo Date2 = ReadFullDateData();
	if (IsDate1BeforeDate2(Date1, Date2))
	{
		cout << "Date1 Is Less Than Date2\n";
	}
	else if (Is2DatesAreEqual(Date1, Date2)) {
		cout << "\n\nTwo Dates Are Equal \n\n";
	}
	else {
		cout << "Date1 Is Not Less Than Date2";
	}
}
