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


int ReverseNum(int Num){
    int Remainder = 0 ;
    int ReverseNum  = 0 ;
    while (Num > 0)
    {
        Remainder = Num % 10 ; 
        Num /= 10 ; 
        ReverseNum = ReverseNum * 10 + Remainder;
    }
    return  ReverseNum ;
}

bool IsPalindorm(int Num ){
    return Num == ReverseNum(Num) ;
}

int main(){
    if (IsPalindorm(ReadPostiveNumber("Please Enter a Postive Num : ")))
        cout << "\n Yes it's a palindorm number \n" ;
    else
        cout << "\n No it is not a palindorm number \n" ;
}