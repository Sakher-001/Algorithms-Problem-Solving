#include <iostream>
#include <string>
using namespace std ;

int ReadAge(){
    int Age ;
    cout << "Enter Your Age? " ;
    cin >> Age ; 
    return Age ;
}

bool ValidateNumberInRange(int Number , int From , int To){
    return (Number >= From && Number <= To) ; // Return True Or False ( cuz  Type IS Bool ) ;
}

int ReadUntillAgeBetween(int From , int To){
    int Age = 0 ;
    do
    {
        Age = ReadAge() ;
    } while (!ValidateNumberInRange(Age , From , To));
    return Age ;
}


void PrintResult(int Age){
    if (ValidateNumberInRange(Age , 18 , 45))
    cout << Age << " Is a Valid age \n" ;
    else
    cout << Age << " Is a Invalid age \n" ;

}

int main(){
    PrintResult(ReadUntillAgeBetween(18 , 45));
    return 0 ;
}