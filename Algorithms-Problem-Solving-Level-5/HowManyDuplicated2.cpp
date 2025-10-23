#include <iostream>
#include <string>
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

int CountDigitFrequency(short DigitToCheck , int Number){
    int FreqCount = 0 ;
    int Remainder = 0 ;
    while (Number > 0)
    {
        Remainder = Number % 10 ; 
        Number /= 10 ;
        if (DigitToCheck == Remainder)  
        {
            FreqCount++ ; 
        }
    }
    return FreqCount ;
}


void PrintAllDigits(int Num){
    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = 0 ;
        DigitFrequency = CountDigitFrequency(i, Num);
        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is "  
            << DigitFrequency << " Time(s).\n";
        }
    }
    
}

int main(){
    int Number = ReadPostiveNumber("Please Enter main Number");
    PrintAllDigits(Number);
}