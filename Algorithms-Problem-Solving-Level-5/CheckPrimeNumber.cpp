#include <iostream>
#include <string>
#include <cmath>


using namespace std ; 

int ReadPostiveNumber(string Message){
    int Number = 0;  
    do
    {
        cout << Message << endl;  
        cin >> Number;            
    } while (Number <= 0);         

    return Number;  
};

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };


enPrimNotPrime CheckPrime(int Number){
    int M = round(Number / 2) ;
    if (Number <= 1)
        return enPrimNotPrime::NotPrime ;
    
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrimNotPrime::NotPrime ;
    }
    return enPrimNotPrime::Prime ;
}


void PrintPrimeNumber(int Number){
    if (CheckPrime(Number) == enPrimNotPrime::NotPrime)
    {
        cout << "Not Prime Number " ;
    }else{
        cout << "Prime Number " ;
    }
    
}

int main(){
    PrintPrimeNumber(ReadPostiveNumber("Please Enter a postive Number : "));
}