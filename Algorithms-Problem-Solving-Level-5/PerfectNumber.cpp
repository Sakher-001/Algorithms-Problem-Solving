#include <iostream>
using namespace std ;


int ReadNum() {
    int Num ;
    cout << "Enter Num for Check if The Number is Perfect? " ;
    cin >> Num ;
    return Num ;
}

void CheckNum(int Num){
    int Sum = 0 ;
    for (int i = 1; i < Num; i++)
    {
        if(Num % i != 0){
            continue;
        }else{
            Sum += i ;
        }
    }
    if (Sum == Num)
    {
        cout << Num <<" is Perfect \n" ;
    }else{
        cout << Num << " is not Perfect \n" ;
    }
    
}

int main(){
    CheckNum(ReadNum()) ;
}