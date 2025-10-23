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

void InvertedLetters(int Num){
    int Letters = Num + 64 ;
    for (char i = Letters; i >= 65 ; i--)
    {
        for (int j = 65; j <= i ; j++)
        {
            cout << i ;
        }
        cout << "\n" ;
    }
    
}

int main(){
    InvertedLetters(ReadPostiveNumber("Please Enter a postive Num : ")) ;
}