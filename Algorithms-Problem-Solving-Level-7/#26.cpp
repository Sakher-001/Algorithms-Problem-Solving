#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string ReadString() {
    string St;
    cout << "PLease Enter a String : ";
    getline(cin, St);
    return St;
}

string PrintWordWithUpperCase(string St) {
    for (int i = 0; i < St.length(); i++) {
        St[i] = toupper(St[i]);
    }
    return St; 
}

string PrintWordWithLowerCase(string St) {
    for (int i = 0; i < St.length(); i++) {
        St[i] = tolower(St[i]);
    }
    return St;
}


int main()
{
    string MySt = ReadString();
    cout << "Word After UpperCase : \n";
    cout << PrintWordWithUpperCase(MySt) <<endl << endl;
    cout << "Word After LowerCase : \n";
    cout << PrintWordWithLowerCase(MySt) << endl;
}