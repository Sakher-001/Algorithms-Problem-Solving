// Power Number for pow(2,3,4) Without Function ;

#include <iostream>
#include <string>
using namespace std ;

int ReadNumber(){
    int N ;
    cout << "Enter a Number? " ;
    cin >> N ;
    return N ;
}

void CalcPowerOf2_3_4(int N){
    int a , b , c;
    a = N * N ;
    b = N * N * N ;
    c = N * N * N * N ;
    cout << "Power Of 2 = " << a << endl << "Power Of 3 = " << b << endl << "Power Of 4 = " << c << endl ;
}

int main(){
    CalcPowerOf2_3_4(ReadNumber());
    return 0 ;
}