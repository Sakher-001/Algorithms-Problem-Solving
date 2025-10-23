#include <iostream>
#include <cmath>
#include <string>
using namespace std ;

void ReadInputs(float& A ,float& B){
    cout << "Enter Width? ";
    cin >> A ;
    cout << "Enter Base? ";
    cin >> B ;
}

float CalcArea(float A , float B){
    const float PI = 3.14 ;
    float Area = (PI * (pow(B , 2)/4)) * ((2*A-B)/(2*A+B));
    return Area ;
}

void PrintArea(float Area){
    cout << "The Area IS : " << Area << endl ;
}

int main(){
    float A , B ;
    ReadInputs(A , B);
    PrintArea(CalcArea(A , B));
    return 0 ;
}