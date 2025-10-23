#include <iostream>
#include <string>
using namespace std ; 

int ReadNum(){
    int Num ; 
    cout << "Enter a Postive Num : " ;
    cin >> Num ;
    return Num ;
}

void ReverseNum(int Num){
    int Reminder = 0 ;
    while (Num > 0)
    {
        Reminder = Num % 10 ;
        Num /= 10 ;
        cout << Reminder << endl ;
    }
}


int main(){
    ReverseNum(ReadNum());
}