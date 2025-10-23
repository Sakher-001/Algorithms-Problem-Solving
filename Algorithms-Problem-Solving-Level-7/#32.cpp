#include <iostream>
#include <cctype>
using namespace std;

char  ReadChar() {
	char Ch1;
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1; 
	return Ch1;
}

bool IsVowel(char Ch) {
	Ch = tolower(Ch);
	return ((Ch == 'a') || (Ch == 'e') || (Ch == 'o') || (Ch == 'u') || (Ch == 'i'));
}


int main()
{
	char Ch = ReadChar();
	if (IsVowel(Ch))
	{
		cout << "YES " << "Letter \'" << Ch << "\' Is Vowel ";
	}
	else {
		cout << "No " << "Letter \'" << Ch << "\' Is't Vowel ";
	}
}
