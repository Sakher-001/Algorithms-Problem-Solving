#include <iostream>
#include <cmath>
#include <string>
using namespace std ;

float ReadLength(){
    int Length ;
    cout << "Enter Circle Length? " ;
    cin >> Length ;
    return Length ;
}

float CalculateArea(int Length){
    const float PI = 3.14159 ;
    float Area = pow(Length , 2) / (4 * PI);
    return Area ;
}

void PrintResult(float Area){
    cout << "The Area IS  = " << Area ;
}

int main(){
    PrintResult(CalculateArea(ReadLength()));
    return 0 ;
}