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
	bool MarkForDelete = false;
};

enum enMainMenu {
	ShowAllClient = 1,
	NewClient,
	DeleteClient,
	UpdateClient,
	FindClient,
	Transiction,
	Exit
};

enum enTransictonMenu {
	Deposit  = 1,
	WithDraw , 
	TotalBalance ,
	ReturnToMainMenu
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
	vector <string> vClientData = SplitString(Line, Speretor);
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
	MyFile.open(FileName, ios::in);
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

void ReturnToTransictionMenu() {
	cout << "Press any key to return to transictions Menu...";
	cin.ignore();
	cin.get();
}
void ReturnMainMenu() {
	cout << "Press any key to return to MainMenu...";
	cin.ignore();
	cin.get();
}

// ======================= St : AddClients ========================

bool IsAccountNumberIsExist(string & AccNum , vector <ClientInfo> & vClients){
	for (ClientInfo& Line : vClients) {
		if (Line.AccountNum == AccNum) {
			return true;
		}
	}
	return false;
}

ClientInfo ReadNewClient() {
	ClientInfo C1;
	vector <ClientInfo> vExistingClients = LoadClientsDataFromFile(FileName);
	do
	{
	cout << "Enter Account Number : ";
	getline(cin >> ws, C1.AccountNum);
	if (IsAccountNumberIsExist(C1.AccountNum , vExistingClients)) {
		cout << "The Account Number Is Used \n";
	}
	else {
		break;
	}
	} while (true);
	cout << "Enter Pin Code : ";
	getline(cin, C1.PinCode);
	cout << "Enter Your Name : ";
	getline(cin, C1.Name);
	cout << "Enter Your Phone : ";
	getline(cin, C1.Phone);
	cout << "Enter Your Account Balance : ";
	cin >> C1.AccountBalance;
	return C1;
}

string ConvertRecordToLine(ClientInfo C1, string Speretor = "#//#") {
	string RecordLine = "";
	RecordLine += C1.AccountNum + Speretor;
	RecordLine += C1.PinCode + Speretor;
	RecordLine += C1.Name + Speretor;
	RecordLine += C1.Phone + Speretor;
	RecordLine += to_string(C1.AccountBalance);
	return RecordLine;
}
void AddDataLineToFile(string FileName, string stDataLine) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}

}

void AddNewClient() {
	ClientInfo NewClient = ReadNewClient();
	AddDataLineToFile(FileName, ConvertRecordToLine(NewClient));
}

void AddClients() {
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "-------------------------------------------------\n";
		cout << "\t\tAdd New Client " << "\n-------------------------------------------------\n";
		AddNewClient();
		cout << "Client Added Successfully , Do You Want To Add More ? Y|N : ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

// ======================= End : AddClients ========================


// ======================= St : DeleteClients ========================
string ReadAccNum() {
	string AccNum;
	cout << "\nPlease Enter Account Number To Search: ";
	getline(cin >> ws , AccNum);
	return AccNum;
}

void PrintClientData(const ClientInfo& Client) {
	cout << "-----------------------------------\n";
	cout << "Account Number : " << Client.AccountNum << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Balance        : " << Client.AccountBalance << endl;
	cout << "-----------------------------------\n";
}

bool MarkClientForDelete(string AccNum, vector<ClientInfo>& vClients) {
	for (ClientInfo& C : vClients) {
		if (C.AccountNum == AccNum) {
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

void SaveClientsDataToFile(string FileName, vector<ClientInfo> vClients) {
	fstream MyFile(FileName, ios::out);
	if (MyFile.is_open()) {
		for (ClientInfo C : vClients) {
			if (!C.MarkForDelete)
				MyFile << 
				ConvertRecordToLine(C) << endl;
		}
		MyFile.close();
	}
}

bool DeleteClientByAccNumber(vector<ClientInfo> & vClients) {
	cout << "-------------------------------------------------\n";
	cout << "\t\tDelete Client " << "\n-------------------------------------------------\n";
	string AccNum = ReadAccNum();
	char Answer = 'n';
	for (ClientInfo& C : vClients) {
		if (C.AccountNum == AccNum) {
			cout << "\nThe following is the client data:\n";
			PrintClientData(C);
			cout << "\n\nDo You Want To Delete This Account ? Y/N : ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y') {
				C.MarkForDelete = true;
				SaveClientsDataToFile(FileName, vClients);
				cout << "\nClient Deleted Successfully\n";
			}
			return true; 
		}
	}

	cout << "\nClient With Account Number (" << AccNum << ") Is Not Found\n";
	return false;
}

// ======================= End : DeleteClients ========================

// ======================= St : Update Clients ========================

bool UpdateClientByAccNumber(vector <ClientInfo>& vClient) {
	cout << "-------------------------------------------------\n";
	cout << "\t\tUpdate Client " << "\n-------------------------------------------------\n";
	string AccNum = ReadAccNum();
	char Answer = 'n';
	for (ClientInfo& C1 : vClient) {
		if (C1.AccountNum == AccNum)
		{
			PrintClientData(C1);
			cout << "\nDo You Want To Update This Account ? Y/N : ";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y')
			{
				C1 = ReadNewClient();
				SaveClientsDataToFile(FileName, vClient);
				vClient = LoadClientsDataFromFile(FileName);
				cout << "\nClient Updated Successfully\n";
				return true;
			}
			else {
				break;
			}
		}
	}
	cout << "\nClient With Account Number (" << AccNum << ") Is Not Found\n";
	return false;
}
// ======================= End : Update Clients ========================


// ======================= St : Find CLient ========================

void FindClientByAccountNumber(vector <ClientInfo> & vClients) {
	
	string AccNum = ReadAccNum();
	bool Found = false;
	for (ClientInfo & C : vClients) {
		if (C.AccountNum == AccNum)
		{
			cout << "\nThe following is the client data:\n";
			Found = true;
			PrintClientData(C);
			break;
		}
	}
	if (!Found)
	{
		cout << "Account Number With (" << AccNum << ") Is Not Found \n";
	}
}

// ======================= End : Find CLient ========================



// ======================= St : Transiction ========================
short ReadUserSelect() {
	short Num;
	cout << "Please Enter Your Choice : ";
	cin >> Num;
	return Num;
}

void PrintTransictionMenu() {
	cout << "-------------------------------------------------\n";
	cout << "\t\tTransiction Menu" << "\n-------------------------------------------------\n";
	cout << "[1] Deposit." << endl;
	cout << "[2] WithDraw." << endl;
	cout << "[3] TotalBalance." << endl;
	cout << "[4] Main Menu." << endl;
}

void DepositClient(vector <ClientInfo> &vClients) {
	cout << "-------------------------------------------------\n";
	cout << "\t\tDeposit Screen" << "\n-------------------------------------------------\n";
	string AccNum = ReadAccNum();
	char Answer = 'n';
	bool Found = false;
	for (ClientInfo& C1 : vClients) {
		if (C1.AccountNum == AccNum)
		{
			Found = true;
			PrintClientData(C1);
			int Amount;
			cout << "Please Enter Your Deposit Amount : ";
			cin >> Amount;
			cout << "\nAre You Sure You Want To Confirm This Transiction ? Y/N : ";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				C1.AccountBalance += Amount;
				SaveClientsDataToFile(FileName, vClients);
				vClients = LoadClientsDataFromFile(FileName);
				cout << "\nClient Transiction Successfully\n";
			}
			else {
				cout << "\nClient Transiction Decliend\n";
			}
			
		}
	}
	if (!Found){
		cout << "Account Number With (" << AccNum << ") Is Not Found \n";
	}
}

void WithDrawClient(vector <ClientInfo>& vClients) {
	cout << "-------------------------------------------------\n";
	cout << "\t\tWithDraw Screen" << "\n-------------------------------------------------\n";
	string AccNum = ReadAccNum();
	char Answer = 'n';
	bool Found = false;
	for (ClientInfo& C1 : vClients) {
		if (C1.AccountNum == AccNum)
		{
			Found = true;
			PrintClientData(C1);
			int Amount;
			cout << "Please Enter Your WithDraw Amount : ";
			cin >> Amount;
			cout << "\nAre You Sure You Want To Confirm This Transiction ? Y/N : ";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y') {
				C1.AccountBalance -= Amount;
				SaveClientsDataToFile(FileName, vClients);
				vClients = LoadClientsDataFromFile(FileName);
				cout << "\nClient Transiction Successfully\n";
			}
			else {
				cout << "\nClient Transiction Decliend\n";
			}

		}
	}
	if (!Found){
		cout << "Account Number With (" << AccNum << ") Is Not Found \n";
	}

}



void PrintTotalBalance(vector <ClientInfo> & vClients) {
	int SumBalance = 0;
	cout << "\n\t\t\t\t\t Client List (" << vClients.size() << ") Client(s).";
	cout << "\n--------------------------------------------------";
	cout << "--------------------------------------------\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n--------------------------------------------------";
	cout << "--------------------------------------------\n" << endl;
	for (ClientInfo & Client : vClients) {
		cout << "| " << left << setw(15) << Client.AccountNum;
		cout << "| " << left << setw(40) << Client.Name;
		cout << "| " << left << setw(12) << Client.AccountBalance;
		SumBalance += Client.AccountBalance;
		cout << endl;
	}
	cout << "\n--------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;
	cout << "\t\t\tTotal Balance = " << SumBalance << "\n\n";
}

void ShowTransictionMenuLoop() {
	short choice;
	do {
		system("cls");
		PrintTransictionMenu();
		choice = ReadUserSelect();
		switch (choice) {
		case Deposit: {
			system("cls");
			vector<ClientInfo> vClients = LoadClientsDataFromFile(FileName);
			DepositClient(vClients);
			ReturnToTransictionMenu();
			break;
		}
		case WithDraw: {
			system("cls");
			vector<ClientInfo> vClients = LoadClientsDataFromFile(FileName);
			WithDrawClient(vClients);
			ReturnToTransictionMenu();
			break;
		}
		case TotalBalance: {
			system("cls");
			vector<ClientInfo> vClients = LoadClientsDataFromFile(FileName);
			PrintTotalBalance(vClients);
			ReturnToTransictionMenu();
			break;
		}
		case ReturnToMainMenu:
			break;
		default:
			cout << "Invalid choice!";
			ReturnToTransictionMenu();
		}
	} while (choice != ReturnToMainMenu);
}

// ======================= End : Transiction ========================

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



short WhatUserSelect() {
	short Num = ReadUserSelect();
	switch (Num) {
	case ShowAllClient: {
		system("cls");
		vector <ClientInfo> vClients = LoadClientsDataFromFile(FileName);
		PrintAllClientsData(vClients);
		ReturnMainMenu();
		break;
	}
	case NewClient: {
		system("cls");
		AddClients();
		ReturnMainMenu();
		break;
	}
	case DeleteClient: {
		system("cls");
		vector <ClientInfo> vDataClients = LoadClientsDataFromFile(FileName);
		DeleteClientByAccNumber(vDataClients);		
		ReturnMainMenu();
		break;
	}
	case UpdateClient: {
		system("cls");
		vector <ClientInfo> vDataClients = LoadClientsDataFromFile(FileName);
		UpdateClientByAccNumber(vDataClients);
		ReturnMainMenu();
		break;
	}
	case FindClient: {
		system("cls");
		cout << "-------------------------------------------------\n";
		cout << "\t\tFind Client " << "\n-------------------------------------------------\n";
		vector <ClientInfo> vClients = LoadClientsDataFromFile(FileName);
		FindClientByAccountNumber(vClients);		
		ReturnMainMenu();
		break;
	}
	case Transiction :{
		system("cls");
		ShowTransictionMenuLoop();
		ReturnMainMenu();
		break;
	}
	case Exit:
		system("pause");
		break;
	default:
		cout << "\nIncorrect Answer \n";
		system("pause");
		break;
	}
	return Num;
}

void PrintMainMenu() {
	cout << "\n--------------------------------------------------";
	cout << "\n\t\t\tMain Menu \n";
	cout << "--------------------------------------------------\n" << endl;
	cout << "[1] Show All Clients." << endl;
	cout << "[2] Add New Clients." << endl;
	cout << "[3] Delete Clients." << endl;
	cout << "[4] Update Clients." << endl;
	cout << "[5] Find Clients." << endl;
	cout << "[6] Transiction." << endl;
	cout << "[7] Exit." << endl;
}




int main() {
	short choice;
	do {
		system("cls");
		PrintMainMenu();
		choice = WhatUserSelect();
	} while (choice != Exit);
	return 0;
}