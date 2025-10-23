#include <iostream>
#include <string>
using namespace std ;

void PrintNumbersFrom1ToN_With_ForLoop(int Num){
    for (int i = Num; i > 0; i--)
    {
        cout << i << endl; 
    }
    
}

void PrintNumbersFrom1ToN_With_WhileLoop(int Num){
    int i = Num ;
    while (i > 0)
    {
        cout << i << endl; 
        i-- ;
    }
    
}

void PrintNumbersFrom1ToN_With_DoWhileLoop(int Num){
    int i = Num ;
    do
    {
        cout << i << endl; 
        i--;
    } while (i > 0);
    
}


int main(){
    int N = ReadNumber() ;
    PrintNumbersFrom1ToN_With_ForLoop(N);
    PrintNumbersFrom1ToN_With_WhileLoop(N);
    PrintNumbersFrom1ToN_With_DoWhileLoop(N);
    return 0 ;
}