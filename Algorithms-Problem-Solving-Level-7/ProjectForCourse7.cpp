#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <iomanip>

using namespace std;

struct ClientInfo {
    string AccountNum;
    string PinCode;
    string Name;
    string Phone;
    string AccountBalance;
    bool MarkForDelete = false;
    bool Update = false;
};

enum enMainMenu {
    ShowClients = 1,
    AddClient = 2,
    DeleteCLient,
    UpdateCLient,
    FindClient,
    Exit
};

// ===== Global Variable =====
string FileName = "MyFile.txt";

// ===== Functions =====



string ReadAccNum() {
    string AccNum;
    cout << "Please Enter AccNumber To Search Clients : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, AccNum);
    return AccNum;
}

vector<string> vLoadDataFromFile(string FileName) {
    vector<string> vLoadDataIntoVector;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            vLoadDataIntoVector.push_back(Line);
        }
        MyFile.close();
    }
    return vLoadDataIntoVector;
}

vector<string> SplitString(string St, string Sperator) {
    vector<string> WordsInArr;
    short Pos = 0;
    string Word;
    while ((Pos = St.find(Sperator)) != std::string::npos) {
        Word = St.substr(0, Pos);
        if (Word != "")
            WordsInArr.push_back(Word);
        St.erase(0, Pos + Sperator.length());
    }
    if (St != "")
        WordsInArr.push_back(St);
    return WordsInArr;
}

// ================== St : Show All Clients =======================

vector<ClientInfo> ParseClients() {
    vector<string> vClientData = vLoadDataFromFile(FileName);
    vector<ClientInfo> vClientsData;
    for (string& RecordLine : vClientData) {
        vector<string> ClientDataParts = SplitString(RecordLine, "#//#");
        if (ClientDataParts.size() == 5) {
            ClientInfo Client;
            Client.AccountNum = ClientDataParts[0];
            Client.PinCode = ClientDataParts[1];
            Client.Name = ClientDataParts[2];
            Client.Phone = ClientDataParts[3];
            Client.AccountBalance = ClientDataParts[4];
            vClientsData.push_back(Client);
        }
    }
    return vClientsData;
}

void PrintAllClients(const vector<ClientInfo>& vClients) {
    cout << string(90, '_') << "\n";
    cout << endl << left
        << "| " << setw(15) << "Account Number"
        << "| " << setw(10) << "PinCode"
        << "| " << setw(20) << "Name"
        << "| " << setw(15) << "Phone"
        << "| " << setw(10) << "Balance" << endl;

    cout << string(90, '_') << "\n\n";

    for (const ClientInfo& Client : vClients) {
        cout << left
            << "| " << setw(15) << Client.AccountNum
            << "| " << setw(10) << Client.PinCode
            << "| " << setw(20) << Client.Name
            << "| " << setw(15) << Client.Phone
            << "| " << setw(10) << Client.AccountBalance << endl;
    }
    cout << string(90, '_') << "\n";
}

ClientInfo ConvertLineToClient(string Line, string Seperator) {
    ClientInfo Client;
    vector<string> vParts = SplitString(Line, Seperator);
    if (vParts.size() == 5) {
        Client.AccountNum = vParts[0];
        Client.PinCode = vParts[1];
        Client.Name = vParts[2];
        Client.Phone = vParts[3];
        Client.AccountBalance = vParts[4];
    }
    return Client;
}

// ================== End : Show All Clients =======================



// ================== St : Add New Client   ========================

ClientInfo ReadNewClientData(ClientInfo C1) {
    cout << "Enter Account Number : ";
    getline(cin >> ws, C1.AccountNum);
    cout << "Enter Pin Code : ";
    getline(cin, C1.PinCode);
    cout << "Enter Your Name : ";
    getline(cin, C1.Name);
    cout << "Enter Your Phone : ";
    getline(cin, C1.Phone);
    cout << "Enter Your Account Balance : ";
    getline(cin, C1.AccountBalance);
    return C1;
}

bool IsAccountNumberUsed(const vector<ClientInfo>& clients, const string& accNum) {
    for (const ClientInfo& client : clients) {
        if (client.AccountNum == accNum) return true; 
    }
    return false; 
}

bool CheckWantToAdd() {
    char WantToAdd;
    cout << "Client Added Successfully , Do You Want To Add More CLient  (Y/N) ? ";
    cin >> WantToAdd;
    cin.ignore();
    return (WantToAdd == 'Y' || WantToAdd == 'y');
}

string ConvertRecordClient(ClientInfo C1, string Speretor = "#//#") {
    string RecordLine = "";
    RecordLine += C1.AccountNum + Speretor;
    RecordLine += C1.PinCode + Speretor;
    RecordLine += C1.Name + Speretor;
    RecordLine += C1.Phone + Speretor;
    RecordLine += C1.AccountBalance + Speretor;
    return RecordLine;
}

void SendClientDataToFile(string RecordLine) {
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::out | ios::app); // write mode
    if (MyFile.is_open())
    {
        MyFile << RecordLine << endl;
        MyFile.close();
    }
}

// ================== End : Add New Client   ========================

short ReadMenuSelect() {
    short NumSelected = 0;
    cout << "Choose What do You Want To Do ? ";
    cin >> NumSelected;
    return NumSelected;
}

short WhatUserSelect() {
    short Num = ReadMenuSelect();
    switch (Num) {
    case ShowClients: {
        vector<ClientInfo> clients = ParseClients();
        system("cls");
        PrintAllClients(clients);
        system("pause");
        break;
    }
    case AddClient: {
        system("cls");
        ClientInfo NewClient;
        string RecordLine;
        vector <ClientInfo> ClientsData = ParseClients(); 
        do
        {
            NewClient = ReadNewClientData(NewClient);
            RecordLine = ConvertRecordClient(NewClient);
            if (IsAccountNumberUsed(ClientsData , NewClient.AccountNum))
            {
                cout << "Can't Added This Account Number Is Used .";
                system("pause");
            }
            else {
                RecordLine = ConvertRecordClient(NewClient);
                SendClientDataToFile(RecordLine);
            }
        } while (CheckWantToAdd());
        system("pause");
        break;
    }
    case DeleteCLient: {
        system("cls");
        // Codes Here ;
        system("pause");
        break;
    }
    default:
        cout << "\nIncorrect Answer \n";
        system("pause");
        break;
    }
    return Num;
}

void PrintMainMenu() {
    cout << "==================================\n";
    cout << "==\tMain Menu Screen\t==\n";
    cout << "==================================\n";
    cout << "[1] Show Client List." << endl;
    cout << "[2] Add New Client." << endl;
    cout << "[3] Delete Client." << endl;
    cout << "[4] Update Client Info." << endl;
    cout << "[5] Find Client." << endl;
    cout << "[6] Exit." << endl;
    cout << "==================================\n\n\n";
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
