#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*-----------------------------------Method-1-------------------
string JoinStrings(vector <string> vElements, string Sperator) {
	string Word = "";
	for (int i = 0; i < vElements.size(); i++)
	{
		if (i < (vElements.size() - 1))
			Word = Word.append(vElements[i] + Sperator);
		else
			Word = Word.append(vElements[i]);
	}
	return Word;
}
*/
 


// Method 2 : 

string JoinString(vector <string> vElements, string Sperator) {
	string S1;
	for (string& Word : vElements) {
		S1 = S1 + Word + Sperator;
	}
	return S1.substr(0, S1.length() - Sperator.length());
}

// JoinString OverLoadingFunction 

string JoinString(string ArrOfElements[], short Length , string Sperator) {
	string S1 = "";
	for (int i = 0; i < Length; i++)
	{
		S1 = S1 + ArrOfElements[i] + Sperator; 
	}
	// Erase Last Join

	return S1.substr(0, S1.length() - Sperator.length());
}

int main()
{
	vector <string> vElements = { "Mohamed" , "Ahmed" , "Ali" , "Sakher" };
	string Arr[] = { "Mohamed" , "Ahmed" , "Ali" , "Sakher" };
	cout << "String After Join : \n";
	cout << JoinString(vElements, "@");
	cout << "\nString After Join OverLoading : \n";
	cout << JoinString(Arr ,4 , "*");
}