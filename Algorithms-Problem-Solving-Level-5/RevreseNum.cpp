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
    int Remainder = 0 ;
    int ReverseNum  = 0 ;
    while (Num > 0)
    {
        Remainder = Num % 10 ; 
        Num /= 10 ; 
        ReverseNum = ReverseNum * 10 + Remainder;
    }
    cout << ReverseNum ;
}


int main(){
    ReverseNum(ReadNum());
}