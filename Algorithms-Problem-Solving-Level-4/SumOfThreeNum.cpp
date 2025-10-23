#include <iostream>
#include <string>

using namespace std ;

void ReadNumbers(int& Num1 , int& Num2 , int& Num3){
    cout << "Please Enter Your First Number? " << endl ; 
    cin >> Num1 ;
    cout << "Please Enter Your Second Number? " << endl ; 
    cin >> Num2 ;
    cout << "Please Enter Your Third Number? " << endl ; 
    cin >> Num3 ;
}

int SumOf3Numbers(int Num1 , int Num2 , int Num3){
    return Num1 + Num2 + Num3;
};

void PrintResults(int Total){
    cout << "\n The Total Sum Of Numbers Is : " << Total  << endl ;
}

int main(){
    int Num1 , Num2 , Num3 ;
    ReadNumbers(Num1 , Num2 , Num3);
    PrintResults(SumOf3Numbers(Num1 , Num2 , Num3));
    return 0 ;
}