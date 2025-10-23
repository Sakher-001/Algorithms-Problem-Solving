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
}

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };


enPrimNotPrime CheckPrime(int Number){ // 7
    int M = round(Number / 2); // 3
    if (Number <= 1){
        return enPrimNotPrime::NotPrime;  
    }
    
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;  
    }
    return enPrimNotPrime::Prime;

}


void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << "\n";  
    cout << "Prime Numbers from " << 1 << " To " << Number;
    cout << " are : " << endl;

    for (int i = 2; i <= Number; i++)
    {
        
        if (CheckPrime(i) == enPrimNotPrime::Prime)
        {
            cout << i << endl;
        }
    }
}

int main(){
    PrintPrimeNumbersFrom1ToN(ReadPostiveNumber("Please Enter a Postive Number : "));
}