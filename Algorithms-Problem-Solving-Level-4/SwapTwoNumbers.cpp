#include <iostream>
#include <string>
using namespace std ;

void ReadNumbers(int& Num1 ,int& Num2){
    cout << "Enter First Num?" ;
    cin >> Num1 ;
    cout << "Enter Second Num?" ;
    cin >> Num2 ;
}

void Swap(int& Num1 , int& Num2){
    int Temp ; // To Save Value From Num1 :>) ;10
    Temp = Num1 ;
    Num1 = Num2 ;
    Num2 = Temp ;
};

void PrintResult(int Num1 , int Num2){
    cout << "The First Num : " << Num1 << endl;
    cout << "The Second Num : " << Num2 << endl;
};

int main(){
    int Num1 , Num2 ;
    ReadNumbers(Num1 , Num2);
    PrintResult(Num1 , Num2);
    Swap(Num1 , Num2);
    PrintResult(Num1 , Num2);
    return 0 ;
}