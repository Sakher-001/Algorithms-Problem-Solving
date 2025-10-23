#include <iostream>
#include <string>
#include <cmath>
using namespace std ; 


float GetFractionPart(float Num){
    return Num - (int)Num;
}

int MyFloor(float Num){
    int intPart = (int) Num ;
    float FractionPart = GetFractionPart(Num) ;
    if (abs(FractionPart) > 0.0){
        if (Num > 0)
            return intPart ;
        else
            return --intPart ;
    }else
        return intPart ;
}

int CPPFloor(float Num){
    return floor(Num);
}

int main(){
    float Num ;
    cout << "Please Enter a Num : " ;
    cin >> Num ;
    cout << "MYY Floor : " << MyFloor(Num)  << endl; 
    cout << "C++ Floor : " << CPPFloor(Num) << endl ;
}