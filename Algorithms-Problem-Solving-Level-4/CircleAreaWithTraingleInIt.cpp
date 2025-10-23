#include <iostream>
#include <string>
#include <cmath>
using namespace std ;

void ReadLengths(float& A , float& B){
    cout << "Enter First Side? " ;
    cin >> A ;
    cout << "Enter Second Side? " ;
    cin >> B ;
}

float CalcArea(float A , float B){
    const float PI = 3.14159 ;
    float T = pow(B , 2) / 4 ;
    float Q = (2 * A - B)/(2 * A + B); 
    float Area = PI * Q * T ;
    return Area ;
}

void PrintResult(float Area){
    cout << "The Area IS  = " << Area ;
}

int main(){
    float A , B ;
    ReadLengths(A , B) ;
    PrintResult(CalcArea(A , B));
    return 0 ;
}