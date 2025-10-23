#include <iostream>
#include <string>
#include <cmath>
using namespace std ; 


float GetFractionPart(float Num){
    return Num - (int)Num;
}

int MyRound(float Num){
    int intPart = (int) Num ;
    float FractionPart = GetFractionPart(Num) ;
    if (abs(FractionPart) > 0.4){
        if (Num > 0)
            return ++intPart ;
        else
            return --intPart ;
    }else
        return intPart ;
}

int CPPRound(float Num){
    return round(Num);
}

int main(){
    float Num ;
    cout << "Please Enter a Num : " ;
    cin >> Num ;
    cout << "MYY Round : " << MyRound(Num)  << endl; 
    cout << "C++ Round : " << CPPRound(Num) << endl ;
}