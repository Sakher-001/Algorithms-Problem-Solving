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

void LettersPattern(int Num){
    int Letters = Num + 64 ;
    for (char i = 65; i <= Letters ; i++)
    {
        for (int j = 65; j <= i ; j++)
        {
            cout << i ;
        }
        cout << "\n" ;
    }
    
}

int main(){
    LettersPattern(ReadPostiveNumber("Please Enter a postive Num : ")) ;
}