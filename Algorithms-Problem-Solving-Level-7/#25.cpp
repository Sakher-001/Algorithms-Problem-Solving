#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string ReadString() {
	string St;
	cout << "PLease Enter a String : ";
	getline(cin, St);
	return St;
}

string PrintLetterLowerCase(string St) {
	St[0] = tolower(St[0]);
	for (short i = 0; i < St.length(); i++) {
		if (St[i] == ' ') {
			St[i + 1] = tolower(St[i + 1]);
		}
	}
	return St;
}

int main()
{
	string MySt = ReadString();
	MySt = PrintLetterLowerCase(MySt);
	cout << MySt;
}