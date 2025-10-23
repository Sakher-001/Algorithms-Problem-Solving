
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Global Variable For File Path : 
const string FileName = "MyFile.txt";

struct ClientInfo {
	string AccountNum;
	string PinCode;
	string Name;
	string Phone;
	string AccountBalance;
};

string ReadAccNum() {
	string AccNum;
	cout << "Please Enter AccNumber To Search Clients : ";
	getline(cin, AccNum);
	return AccNum;
}

vector <string> vLoadDataFromFile(string FileName) {
	vector <string> vLoadDataIntoVector;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line)) {
			vLoadDataIntoVector.push_back(Line);
		}
		MyFile.close();
	}
	return vLoadDataIntoVector;
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

ClientInfo ConvertLineToClient(string Line , string Seperator = "#//#") {
	ClientInfo Client;
	vector <string> vParts = SplitString(Line , Seperator);
	if (vParts.size() == 5)
	{
		Client.AccountNum = vParts[0];
		Client.PinCode = vParts[1];
		Client.Name = vParts[2];
		Client.Phone = vParts[3];
		Client.AccountBalance = vParts[4];
	}
	return Client;
}

bool IsAccNumberIsFound(vector <string> vClientData , string AccNum , ClientInfo & Result) {
	for (string Line : vClientData) {
		ClientInfo Client = ConvertLineToClient(Line);
		if (Client.AccountNum == AccNum) {
			Result = Client;
			return true;
		}
	}
	return false;
}

void PrintClientCard(const ClientInfo& Client) {
	cout << "-----------------------------------\n";
	cout << "Account Number : " << Client.AccountNum << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Balance        : " << Client.AccountBalance << endl;
	cout << "-----------------------------------\n";
}

int main()
{
	ClientInfo Client;
	vector <string> vDataClient = vLoadDataFromFile(FileName);
	string AccNum = ReadAccNum();
	if (IsAccNumberIsFound(vDataClient ,AccNum , Client))
	{
		PrintClientCard(Client);
	}
	else {
		cout << "Error " << AccNum << "Is Undifind :( ";
	}
}