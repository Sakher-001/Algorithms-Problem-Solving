#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString() {
	string St;
	cout << "PLease Enter a String : ";
	getline(cin, St);
	return St;
}

string InverAllLetters(string St) {
	for (int i = 0; i < St.length(); i++) {
		St[i] = isupper(St[i]) ? tolower(St[i]) : toupper(St[i]);
	}
	return St;
}

int main()
{
	string MySt = ReadString();
	cout << "\nWord After Inverting : \n";
	cout << InverAllLetters(MySt);
}