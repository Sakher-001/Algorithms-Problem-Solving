#include <iostream>
#include <cmath>
using namespace std ; 

int MyPower(int Base , int Power){
    if (Power == 0)
    return 1 ;
    else{
        return Base * MyPower(Base , Power - 1) ; // 2 * 2 * 2 * 2
    }
}

int main(){
    cout << MyPower(2 , 4);
}