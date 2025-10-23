#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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
	getline(cin , C1.AccountNum );
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

string ConvertRecordClient(ClientInfo C1, string Speretor = "#//#") {
	string RecordLine = "";
	RecordLine += C1.AccountNum + Speretor;
	RecordLine += C1.PinCode + Speretor;
	RecordLine += C1.Name + Speretor;
	RecordLine += C1.Phone + Speretor;
	RecordLine += to_string(C1.AccountBalance) ;
	return RecordLine; 
}

int main()
{
	cout << "PLease Enter CLient Data  \n\n";
	ClientInfo C1; 
	C1 = ReadNewClient();
	cout << "Client Record Line : \n";
	cout << ConvertRecordClient(C1);
}