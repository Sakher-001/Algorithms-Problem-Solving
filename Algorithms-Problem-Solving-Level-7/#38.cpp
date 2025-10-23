#include <iostream>
#include <string> 
#include <cctype>
using namespace std;

string ReadString() {
    string St;
    cout << "PLease Enter a String : \n";
    getline(cin, St);
    return St;
}

string TrimLeft(string St) {
    for (int i = 0; i < St.length(); i++)
    {
        if (St[i] != ' ') {
            return St.substr(i, St.length() - i);
        }
    }
    return "";
}
// Mohamed    
string TrimRight(string St) {
    for (int i = St.length() - 1; i >= 0; i--)
    {
        if (St[i] != ' ')
        {
            return St.substr(0 , i + 1);
        }
    }
    return "";
}

string Trim(string St) {
    return TrimLeft(TrimRight(St));
}

int main()
{
    string MySt = ReadString();
    cout << "Trim Left  : " << TrimLeft(MySt) << endl;
    cout << "Trim Right : " << TrimRight(MySt)<< endl ;
    cout << "Trim : " << Trim(MySt) << endl;
    cout << MySt[MySt.length() - 2]; // For Check Last ELement In Trim Right ;
}