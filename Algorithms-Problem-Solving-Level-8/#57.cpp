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

bool IsDate1AfterDate2(DateInfo Date1, DateInfo Date2) {
	return (!IsDate1BeforeDate2(Date1, Date2) && !Is2DatesAreEqual(Date1, Date2));
}

short Compare2Dates(DateInfo Date1, DateInfo Date2) {
	if (IsDate1BeforeDate2(Date1 , Date2))
	{
		return -1;
	}
	else if (Is2DatesAreEqual(Date1 , Date2)){
		return 0;
	}
	return 1;
}



int main() {
	cout << "\nEnter Date 1 : " << endl;
	DateInfo Date1 = ReadFullDateData();
	cout << "\nEnter Date 2 : " << endl;
	DateInfo Date2 = ReadFullDateData();
	cout << "Compare Dates Result : " << Compare2Dates(Date1, Date2);
}