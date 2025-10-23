#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

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

string JoinString(vector <string> vElements, string Sperator) {
	string S1;
	for (string& Word : vElements) {
		S1 = S1 + Word + Sperator;
	}
	return S1.substr(0, S1.length() - Sperator.length());
}

string ReplaceWords(string Str, string StrToReplace, string Replace) {
	vector <string> vElement = SplitString(Str, " ");
	for (string& Word : vElement) {
		if (Word == StrToReplace)
		{
			Word = Replace;
		}
	}
	return JoinString(vElement , " ");
}

int main() {
	vector <string> vElements;
	string MySt = "Mohamed Ahmed Ali Ali ali Sakher";
	cout << ReplaceWords(MySt, "Ali", "Ahmed");
}