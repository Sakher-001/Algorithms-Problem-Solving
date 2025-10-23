#include <iostream>
#include <string>
#include <cmath>
using namespace std ; 


int MyABS(int Num){
    if (Num < 0)
        return -Num ;
    else
        return Num ;
}

int CPPABS(int Num){
    return abs(Num);
}

int main(){
    int Num ;
    cout << "Please Enter a Num : " ;
    cin >> Num ;
    cout << "MYY ABS : " << MyABS(Num)  << endl; 
    cout << "C++ ABS : " << CPPABS(Num) << endl ;
}