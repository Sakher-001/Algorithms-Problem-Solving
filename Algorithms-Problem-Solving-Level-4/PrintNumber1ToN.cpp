#include <iostream>
#include <string>
using namespace std ;

int ReadNumber(){
    int Num ;
    cout << "Please Enter Num ? ";
    cin>> Num ;
    return Num ;
}

void PrintNumbersFrom1ToN_With_ForLoop(int Num){
    for (int i = 1; i <= Num; i++){
        cout << i  << endl ;
    }
}

void PrintNumbersFrom1ToN_With_WhileLoop(int Num){
    int i = 1 ;
    while(i <= Num){
        cout << i << endl;
        i++ ;
    }
}

void PrintNumbersFrom1ToN_With_DoWhileLoop(int Num){
    int i = 1 ;
    do
    {
        cout << i << endl;
        i++;
    } while (i <= Num);
    
}

int main(){
    int N = ReadNumber() ;
    PrintNumbersFrom1ToN_With_ForLoop(N);
    PrintNumbersFrom1ToN_With_WhileLoop(N);
    PrintNumbersFrom1ToN_With_DoWhileLoop(N);
    return 0 ;
}