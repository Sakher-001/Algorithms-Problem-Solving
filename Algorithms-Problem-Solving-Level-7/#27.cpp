#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char ReadChar() {
	char Ch1;     
	cout << "Please Enter a Character?\n";     
	cin >> Ch1;
	return Ch1;
}

char InvertChar(char Ch1) {
	return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

int main() {
	char Ch1 = ReadChar();
	cout << "\nChar After Inverting : " << endl;
	cout << InvertChar(Ch1);
}