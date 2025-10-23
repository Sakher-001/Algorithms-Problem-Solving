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

void InvertedNumbers(int Num){
    for (int i = Num; i >= 1 ; i--)
    {
        for (int j = 1; j <= i ; j++)
        {
            cout << i ;
        }
        cout << "\n" ;
    }
    
}

int main(){
    InvertedNumbers(ReadPostiveNumber("Please Enter a postive Num : ")) ;
}