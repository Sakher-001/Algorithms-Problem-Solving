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
vector <string> SplitString(string St, string Sperator) {
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

string ReverseWord(string Str) {
	vector <string> vString;
	string S2 = "";

	vString = SplitString(Str, " ");
	vector <string>::iterator iter = vString.end();
	while (iter != vString.begin()) {
		--iter;
		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1);
	return S2;
}


int main() {
	
	string MySt = ReadString(); 
}