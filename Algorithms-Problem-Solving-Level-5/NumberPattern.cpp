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

void NumberPattern(int Num){
    for (int i = 1; i <= Num ; i++)
    {
        for (int j = 1; j <= i ; j++)
        {
            cout << i ;
        }
        cout << "\n" ;
    }
    
}

int main(){
    NumberPattern(ReadPostiveNumber("Please Enter a postive Num : ")) ;
}