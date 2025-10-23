// Count Characters

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

char ReadChar() {
	char Ch1;
	cout << "PLease Enter a Char To Count : ";
	cin >> Ch1;
	return Ch1;
}

short CountChar(string St , char Char) {
	short Count = 0;
	for (int i = 0; i < St.length(); i++) {
		if (St[i] == Char )
		{
			Count++ ;
		}
	}
	return Count; 
}


int main() {
	string MySt = ReadString();
	char MyCh = ReadChar(); 
	cout << "\nLetter \'" << MyCh << "\' Count = " << CountChar(MySt, MyCh);
}
