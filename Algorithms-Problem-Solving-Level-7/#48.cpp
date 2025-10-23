
// #48 Load Client Data From File

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// Global Variable For File Path : 
const string FileName = "MyFile.txt";

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

ClientInfo ConvertLineToRecord(string Line, string Speretor = "#//#") {
	ClientInfo Client;
	vector <string> vClientData = SplitString(Line , Speretor);
	Client.AccountNum = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);
	return Client;

}


vector <ClientInfo> LoadClientsDataFromFile(string FileName) {
	vector <ClientInfo> vCLients;
	fstream MyFile;
	MyFile.open(FileName , ios::in);
	if (MyFile.is_open())
	{
		string Line;
		ClientInfo Client;
		while (getline(MyFile, Line)) {
			Client = ConvertLineToRecord(Line);
			vCLients.push_back(Client);
		}
		MyFile.close();
	}
	return vCLients;
}


vector <ClientInfo> ParseClients(vector <string> vClientData) {
	vector <ClientInfo> vClientsData;
	for (string& RecordLine : vClientData) {
		vector<string> ClientDataParts = SplitString(RecordLine, "#//#");
		if (ClientDataParts.size() == 5) {
			ClientInfo Client;
			Client.AccountNum = ClientDataParts[0];
			Client.PinCode = ClientDataParts[1];
			Client.Name = ClientDataParts[2];
			Client.Phone = ClientDataParts[3];
			Client.AccountBalance = stod(ClientDataParts[4]);
			vClientsData.push_back(Client);
		}

	}
	return vClientsData; 
}


void PrintClientRecord(ClientInfo Client) {
	cout << "| " << left << setw(15) << Client.AccountNum;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}


void PrintAllClientsData(const vector<ClientInfo>& vClients) {
	cout << "\n\t\t\t\t\t Client List (" << vClients.size() << ") Client(s).";
	cout << "\n--------------------------------------------------";
	cout << "--------------------------------------------\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n--------------------------------------------------";
	cout << "--------------------------------------------\n" << endl;
	for (const ClientInfo Client : vClients) {
		PrintClientRecord(Client);
		cout << endl;
	}
	cout << "\n--------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;
}

int main()
{
	vector <ClientInfo> vClients = LoadClientsDataFromFile(FileName);
	PrintAllClientsData(vClients);
	return 0;
}