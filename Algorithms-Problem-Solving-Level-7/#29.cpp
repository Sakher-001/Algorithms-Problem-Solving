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

void CountLowerAndUpperChar(string St) {
	int CountUpperLetter = 0 , CountLowerLetter = 0;
	for (int i = 0; i < St.length(); i++) {
		isupper(St[i]) ? CountUpperLetter++ : CountLowerLetter++;
	}
	cout << "Count Upper Letter : " << CountUpperLetter << endl;
	cout << "Count Lower Letter : " << CountLowerLetter << endl;
}

int main()
{
	string MySt = ReadString();
	cout << "\nCount Upper & Letter : \n";
	CountLowerAndUpperChar(MySt);
}