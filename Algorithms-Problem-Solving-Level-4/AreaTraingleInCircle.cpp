#include <iostream>
#include <string>
#include <cmath>

using namespace std ;

void ReadValues(float& A , float& B , float& C){
    cout << "Enter First Side? " ;
    cin >> A ;
    cout << "Enter Second Side? " ;
    cin >> B ;
    cout << "Enter Third Side? " ;
    cin >> C ;
}

float CalcArea(float A , float B , float C){
    const float PI = 3.14159 ;
    float P = (A + B + C) / 2 ;
    float T = (A * B * C) / ( 4 * sqrt(P * (P - A) * (P - B) * (P - C))) ;
    float Area = PI * pow(T , 2) ;
    return Area ;
}

void PrintArea(float Area){
    cout << "The Area = " << Area ;
}

int main(){
    float A , B , C ;
    ReadValues(A , B , C);
    PrintArea(CalcArea( A ,  B , C));
    return 0 ;
}