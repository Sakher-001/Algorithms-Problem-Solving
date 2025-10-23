#include <iostream>
#include <string>
#include <cmath>
using namespace std ; 



float MySqrt(float Num){
    return pow(Num , 0.5);
}

float CPPSqrt(float Num){
    return sqrt(Num);
}

int main(){
    float Num ;
    cout << "Please Enter a Num : " ;
    cin >> Num ;
    cout << "MYY Sqrt : " << MySqrt(Num)  << endl; 
    cout << "C++ Sqrt : " << CPPSqrt(Num) << endl ;
}