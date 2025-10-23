
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

struct ClientInfo {
	string AccountNum;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

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

static ClientInfo ConvertLineToRecord(string RecordLine) {
	ClientInfo ClientData;
	vector <string> vClientData = SplitString(RecordLine , "#//#");

		ClientData.AccountNum = vClientData[0];
		ClientData.PinCode = vClientData[1];
		ClientData.Name = vClientData[2];
		ClientData.Phone = vClientData[3];
		ClientData.AccountBalance = stod(vClientData[4]);
	return ClientData;
}


static void PrintClientData(ClientInfo ClientData) {
	cout << "\n\nThe following is the extracted client record:\n";  
	cout << "\nAccout Number: " << ClientData.AccountNum;  
	cout << "\nPin Code     : " << ClientData.PinCode;  
	cout << "\nName         : " << ClientData.Name;
	cout << "\nPhone        : " << ClientData.Phone;   
	cout << "\nAccount Balance : " << ClientData.AccountBalance;
}

int main()
{
	string RecordLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";  
	cout << "\nLine Record is:\n";
	cout << RecordLine;
	// Split String Into Array ;
	ClientInfo ClientData = ConvertLineToRecord(RecordLine);
	PrintClientData(ClientData);
	system("pause>0");
	return 0;
}