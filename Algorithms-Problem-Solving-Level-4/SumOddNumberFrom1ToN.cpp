#include <iostream>
#include <string>
using namespace std ;

int ReadNumber(){
    int Num ;
    cout << "Please Enter Num ? ";
    cin>> Num ;
    return Num ;
}


int PrintNumbersFrom1ToN_With_ForLoop(int Num){
    int Sum = 0 ;
    for (int i = 1; i < Num; i++)
    {
        if (i % 2 != 0)
        {
            Sum += Num;
        }
    }
    return Sum ;
}

void PrintNumbersFrom1ToN_With_WhileLoop(int Num){

}

void PrintNumbersFrom1ToN_With_DoWhileLoop(int Num){

}

int main(){
    int N = ReadNumber() ;
    PrintNumbersFrom1ToN_With_ForLoop(N);
    // PrintNumbersFrom1ToN_With_WhileLoop(N);
    // PrintNumbersFrom1ToN_With_DoWhileLoop(N);
    return 0 ;
}