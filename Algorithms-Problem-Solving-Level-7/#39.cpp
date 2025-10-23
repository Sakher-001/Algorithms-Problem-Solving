#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinStrings(vector <string> vElements, string Sperator) {
	string Word = "";
	for (int i = 0; i < vElements.size(); i++)
	{
		if ( i < (vElements.size() - 1))
		    Word = Word.append(vElements[i] + Sperator);
		else
			Word = Word.append(vElements[i]);
	}
	return Word;
}


// Method 2 : 

string JoinString(vector <string> vElements, string Sperator) {
	string S1;
	for (string& Word : vElements) {
		S1 = S1 + Word + Sperator;
	}
	return S1.substr(0, S1.length() - Sperator.length());
}

int main()
{
    vector <string> vElements = { "Mohamed" , "Ahmed" , "Ali" , "Sakher" };
	cout << "String After Join : \n";
	cout << JoinString(vElements, "@");
}
