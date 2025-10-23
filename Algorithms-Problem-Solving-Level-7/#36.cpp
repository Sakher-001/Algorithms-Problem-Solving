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


int PrintEachWordOfString(string St) {
    string delim = " ";
    short pos = 0;
    string Word ;
    short WordCount = 0;
    while ((pos = St.find(delim)) != std::string::npos) {
        Word = St.substr(0, pos);
        if (Word != "")
        {
            WordCount++;
        }
        St.erase(0, pos + delim.length());
    }
    if (Word != "")
    {
        WordCount++;
    }
    return WordCount;
}

int main()
{
    string MySt = ReadString();
    cout << "\n Number Of Words Is : " << PrintEachWordOfString(MySt);
}