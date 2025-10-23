#include <iostream>
#include <string>
#include <vector>
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

string TransferToLowerCase(string Str) {
	for (int i = 0; i < Str.length(); i++)
	{
		Str[i] = tolower(Str[i]);
	}
	return Str;
}

string ReplaceWordsMatchCase(string Str , string StrToReplace , string Replace , bool Match = true) {
	vector <string> vElement = SplitString(Str, " ");
	for (int i = 0; i < vElement.size(); i++ ) {
		if (Match)
		{
			if (vElement[i] == StrToReplace)
			{
				vElement[i] = Replace;
			}
		}
		else {
			if (TransferToLowerCase(vElement[i]) == TransferToLowerCase(StrToReplace) )
			{
				vElement[i] = Replace;
			}
		}
	}
	return JoinString(vElement, " ");
}





int main()
{
    string S1 = "Welcome to Jordan , jordan is a nice country";
    string StringToReplace = "Jordan"; 
    string ReplaceTo = "USA";

	cout << "Replace String With Match Case : \n"; 
	cout << ReplaceWordsMatchCase(S1, StringToReplace, ReplaceTo , true) << endl ;
	cout << "Replace String Without Match Case : \n";
	cout << ReplaceWordsMatchCase(S1, StringToReplace, ReplaceTo , false) << endl;
}