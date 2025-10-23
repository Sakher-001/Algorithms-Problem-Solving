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

short ConutVowel(string Str ){
	short Counter = 0;
	for (int i = 0; i < Str.length(); i++)
	{
		if (IsVowel(Str[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string Str = ReadStr();
	cout << "\nCount Vowels In String IS : " << ConutVowel(Str);
}