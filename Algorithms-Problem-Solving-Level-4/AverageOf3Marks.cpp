#include <iostream>
#include <string>

using namespace std ;

void ReadNumbers(int& Num1 , int& Num2 , int& Num3){
    cout << "Please Enter First Number ? " ;
    cin >> Num1 ;
    cout << "Please Enter Second Number ? " ;
    cin >> Num2 ;
    cout << "Please Enter Third Number ? " ;
    cin >> Num3 ;
};

int CalculateAverage(int Num1 , int Num2 , int Num3){
    return (Num1 + Num2 + Num3) / 3 ;
}

void PrintResult(int Average){
    cout << "The Average  of Nums Is : " << Average ;
}

int main(){
    int Num1 , Num2 , Num3 ;
    ReadNumbers(Num1 , Num2 , Num3);
    PrintResult(CalculateAverage(Num1 , Num2 , Num3)) ;
    return 0 ;
}