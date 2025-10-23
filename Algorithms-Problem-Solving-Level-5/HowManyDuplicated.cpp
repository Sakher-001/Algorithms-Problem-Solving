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

int main(){
    int Number = ReadPostiveNumber("Please Enter main Number");
    short DigitToCheck = ReadPostiveNumber("Please Enter one digit To check");
    cout << "\nDigit " << DigitToCheck << " Frequency is " << CountDigitFrequency(DigitToCheck , Number)
    << " Time(s).\n" ;
}