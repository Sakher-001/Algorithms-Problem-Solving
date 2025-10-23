#include <iostream>
#include <string>
using namespace std ; 

int ReadNum(){
    int Num ; 
    cout << "Enter a Postive Num : " ;
    cin >> Num ;
    return Num ;
}

void SumOfDigits(int Num){
    int Sum = 0 ;
    int Reminder = 0 ;
    while(Num > 0){
        Reminder = Num % 10 ;
        Num /= 10 ;
        Sum += Reminder ;
    }
        cout << Sum ;
}


int main(){
    SumOfDigits(ReadNum());
}