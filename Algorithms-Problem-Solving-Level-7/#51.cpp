// #51 update CLientData ...
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const string FileName = "MyFile.txt";

struct ClientInfo {
    string AccountNum;
    string PinCode;
    string Name;
    string Phone;
    string AccountBalance;
    bool MarkForDelete = false;
    bool Update = false;
};

ClientInfo ReadData(ClientInfo C1) {
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


string ReadAccNum() {
    string AccNum;
    cout << "Please Enter Account Number To Search: ";
    getline(cin, AccNum);
    return AccNum;
}

vector<string> SplitString(string St, string Separator) {
    vector<string> WordsInArr;
    short Pos = 0;
    string Word;
    while ((Pos = St.find(Separator)) != string::npos) {
        Word = St.substr(0, Pos);
        if (Word != "")
            WordsInArr.push_back(Word);
        St.erase(0, Pos + Separator.length());
    }
    if (St != "")
        WordsInArr.push_back(St);
    return WordsInArr;
}

ClientInfo ConvertLineToClient(string Line, string Separator = "#//#") {
    ClientInfo Client;
    vector<string> vParts = SplitString(Line, Separator);
    if (vParts.size() == 5) {
        Client.AccountNum = vParts[0];
        Client.PinCode = vParts[1];
        Client.Name = vParts[2];
        Client.Phone = vParts[3];
        Client.AccountBalance = vParts[4];
    }
    return Client;
}

string ConvertClientToLine(ClientInfo C, string Separator = "#//#") {
    return C.AccountNum + Separator +
        C.PinCode + Separator +
        C.Name + Separator +
        C.Phone + Separator +
        C.AccountBalance;
}

vector<ClientInfo> LoadClientsDataFromFile(string FileName) {
    vector<ClientInfo> vClients;
    fstream MyFile(FileName, ios::in);
    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            vClients.push_back(ConvertLineToClient(Line));
        }
        MyFile.close();
    }
    return vClients;
}

bool IsAccNumberFound(vector<ClientInfo> vClients, string AccNum, ClientInfo& Result) {
    for (ClientInfo C : vClients) {
        if (C.AccountNum == AccNum) {
            Result = C;
            return true;
        }
    }
    return false;
}




void SaveClientsDataToFile(string FileName, vector<ClientInfo> vClients) {
    fstream MyFile(FileName, ios::out);
    if (MyFile.is_open()) {
        for (ClientInfo C : vClients) {
                MyFile << ConvertClientToLine(C) << endl;
        }
        MyFile.close();
    }
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

bool UpdateClientByAccNumber(string AccNum, vector <ClientInfo>& vClient) {
    char Answer = 'n';
    for (ClientInfo& C1 : vClient) {
        if (IsAccNumberFound(vClient, AccNum, C1))
        {
            PrintClientData(C1);
            cout << "\nDo You Want To Update This Account ? Y/N : ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                C1 = ReadData(C1);
                SaveClientsDataToFile(FileName, vClient);
                vClient = LoadClientsDataFromFile(FileName);
                cout << "\nClient Updated Successfully\n";
                return true;
            }

        }
    }
    cout << "\nClient With Account Number (" << AccNum << ") Is Not Found\n";
    return false;
}

int main() {
    vector<ClientInfo> vDataClients = LoadClientsDataFromFile(FileName);
    string AccNum = ReadAccNum();
    UpdateClientByAccNumber(AccNum, vDataClients);
}