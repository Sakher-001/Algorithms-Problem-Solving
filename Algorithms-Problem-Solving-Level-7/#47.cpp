
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string FileName = "MyFile.txt"; 

struct ClientInfo {
	string AccountNum;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

ClientInfo ReadNewClient() {
	ClientInfo C1;
	cout << "Enter Account Number : ";
	getline(cin >> ws , C1.AccountNum);
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

void AddDataLineToFile(string FileName , string stDataLine) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl ;
		MyFile.close();
	}

}

void AddNewClient() {
	ClientInfo NewClient = ReadNewClient();
	AddDataLineToFile(FileName , ConvertRecordToLine(NewClient));
}

void AddClients() {
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Add New Client : \n\n";

		AddNewClient();
		cout << "Client Added Successfully , Do You Want To Add More ? Y|N : ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();

}