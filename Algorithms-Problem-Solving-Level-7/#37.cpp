#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


string ReadString() {
	string St;
	cout << "PLease Enter a String : ";
	getline(cin, St);
	return St;
}

vector <string> SplitString(string St , string Sperator) {
	vector<string> WordsInArr;
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

int main() {
	vector <string> vElements; 
	string MySt = ReadString();
	vElements = SplitString(MySt , " ");
	cout << "Tokens : " << vElements.size() << endl;
	for (string & Word : vElements) {
		cout << Word << endl;
	}
}