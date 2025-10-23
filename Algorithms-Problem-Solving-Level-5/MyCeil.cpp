#include <iostream>
#include <string>
#include <cmath>
using namespace std ; 


float GetFractionPart(float Num){
    return Num - (int)Num;
}

int MyCeil(float Num){
    int intPart = (int) Num ;
    float FractionPart = GetFractionPart(Num) ;
    if (abs(FractionPart) > 0.0){
        if (Num > 0)
            return ++intPart ;
        else
            return intPart ;
    }else
        return intPart ;
}

int CPPCeil(float Num){
    return ceil(Num);
}

int main(){
    float Num ;
    cout << "Please Enter a Num : " ;
    cin >> Num ;
    cout << "MYY Ceil : " << MyCeil(Num)  << endl; 
    cout << "C++ Ceil : " << CPPCeil(Num) << endl ;
}