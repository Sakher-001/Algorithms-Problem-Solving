#include <iostream>
#include <string>

using namespace std;

string ReadString() {
	string St;
	cout << "PLease Enter a String : "; 
	getline(cin, St);
	return St;
}

void PrintFirstLetterOfEachWord(string St) {
	char FirstLetter = St[0];
	cout << FirstLetter << endl ;
	for (short i = 0; i < St.length(); i++) {
		if (St[i] == ' ')
		{
			cout << St[i + 1] << endl;
		}
	}
}

int main() {
	string MySt = ReadString();
	PrintFirstLetterOfEachWord(MySt);
}