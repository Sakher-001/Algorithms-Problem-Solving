#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DateInfo {
	short Day;
	short Month;
	short Year;
};

string ReadFullDateData() {
	string Date;
	cout << "PLease Enter a Date dd/mm/yyyy : ";
	getline(cin >> ws, Date);
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

bool IsValidDate(DateInfo Date) {
	if (Date.Month > 12 || Date.Month < 1)
		return false;
	if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year) || Date.Day < 1)
		return false;
	return true;
}

vector <string> SplitString(string St, string Sperator) {
	vector <string> WordsInArr;
	short Pos = 0;
	string Word;
	while ((Pos = St.find(Sperator)) != std::string::npos) {
		Word = St.substr(0, Pos);
		if (Word != "")
		{
			WordsInArr.push_back(Word);
		}
		St.erase(0, Pos + Sperator.length());

	}
	if (St != "")
	{
		WordsInArr.push_back(St);
	}
	return WordsInArr;
}

DateInfo StringToDate(string StringDate) {
	DateInfo stDate;
	vector <string> vStringDate = SplitString(StringDate, "/");
	stDate.Day   = stoi(vStringDate[0]);
    stDate.Month = stoi(vStringDate[1]);
	stDate.Year = stoi(vStringDate[2]);
	return stDate;
}

void PrintDate(DateInfo Date) {
	if (IsValidDate(Date))
	{
		cout << "\nDay : " << Date.Day << endl;
		cout << "Month : " << Date.Month << endl;
		cout << "Year : " << Date.Year << endl;
	}
	else {
		cout << "NOT Validate Day\n";
	}
}

string DateToString(DateInfo Date) {
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main() {
	DateInfo Date;
	string DateLine = ReadFullDateData();
	Date = StringToDate(DateLine);
	PrintDate(Date);
	cout << "\nYou Entered : " << DateToString(Date);
};