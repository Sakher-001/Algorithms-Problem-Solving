#include <iostream>
#include <string>
using namespace std ;

void ReadNumber(int& Num1 , int& Num2){
    cout << "Enter First Number? " ;
    cin >> Num1 ;
    cout << "Enter Second Number? "  ;
    cin >> Num2 ;
};

int MaxOf2Numbers(int Num1 , int Num2){
    if (Num1 > Num2)
        return Num1 ;
    else{
        return Num2 ;
    }
    
};


void PrintResults(int Max){
    cout << "The Max Value is : " << Max << endl;
}
int main(){
    int Num1, Num2 ;
    ReadNumber(Num1 , Num2);
    PrintResults(MaxOf2Numbers(Num1 , Num2));
    return 0 ;
}