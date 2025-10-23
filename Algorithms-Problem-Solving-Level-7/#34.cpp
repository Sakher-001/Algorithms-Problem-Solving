#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string  ReadStr() {
	string Str;
	cout << "\nPlease Enter a String?\n";
	cin >> Str;
	return Str;
}


bool IsVowel(char Ch) {
	Ch = tolower(Ch);
	return ((Ch == 'a') || (Ch == 'e') || (Ch == 'o') || (Ch == 'u') || (Ch == 'i'));
}


string PrintAllVowelInString(string Str) {
	for (int i = 0; i < Str.length(); i++)
	{
		if (IsVowel(Str[i])) {
			cout << Str[i];
		}
	}
}

int main()
{
	string Str = ReadStr();
	PrintAllVowelInString(Str);
}