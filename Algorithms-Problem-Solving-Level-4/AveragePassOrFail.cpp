#include <iostream>
#include <string>
using namespace std ;

enum enPassOrFail {Pass = 1 , Fail = 2 } ;

void ReadNumbers(int& Num1 ,int& Num2 , int& Num3 , int& Num4, int& Num5){
    cout << "Enter Your First Number? " ;
    cin >> Num1 ;
    cout << "Enter Your Second Number? " ;
    cin >> Num2 ;
    cout << "Enter Your Third Number? " ;
    cin >> Num3 ;
    cout << "Enter Your Fourth Number? " ;
    cin >> Num4 ;
    cout << "Enter Your Fifth Number? " ;
    cin >> Num5 ;
};

int CalculateAverage(int Num1 ,int Num2 , int Num3 , int Num4, int Num5){
    return (float)(Num1 + Num2 + Num3 + Num4 + Num5 ) / 5 ;
};

enPassOrFail CheckPassOrFail(int Average){
    if(Average >= 50)
    return enPassOrFail::Pass ;
    else
    return enPassOrFail::Fail ;
};

void PrintMassage(int Average){
    if (CheckPassOrFail(Average) == enPassOrFail::Pass)
    cout << "\n You Passed" << endl ;
    else
    cout << "\n You Failed" << endl ;
}

int main(){
    int Num1 , Num2 , Num3 , Num4 , Num5 ;
    ReadNumbers(Num1 , Num2 , Num3 , Num4 , Num5) ;
    PrintMassage(CalculateAverage(Num1 , Num2 , Num3 , Num4 , Num5));
    return 0 ;
}