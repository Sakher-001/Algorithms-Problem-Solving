#include <iostream>
#include <string>
using namespace std ; 

int ReadNum(){
    int Num ; 
    cout << "Enter a Postive Num : " ;
    cin >> Num ;
    return Num ;
}

int ReverseNum(int Num){
    int Remainder = 0 ;
    int ReverseNum  = 0 ;
    while (Num > 0)
    {
        Remainder = Num % 10 ; 
        Num /= 10 ; 
        ReverseNum = ReverseNum * 10 + Remainder;
    }
    return  ReverseNum ;
}

void OrderNums(int Num){
    int Reminder = 0 ;
    while(Num > 0){
        Reminder = Num % 10 ;
        Num /= 10 ;
        cout << Reminder << endl ;
    }
}
int main(){
    OrderNums(ReverseNum(ReadNum())) ;
}