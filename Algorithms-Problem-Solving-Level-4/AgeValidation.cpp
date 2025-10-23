#include <iostream>
#include <string>
using namespace std ;

int ReadAge(){
    int Age ; 
    cout << "Please Enter Your Age ? " ;
    cin >> Age ;
    return Age ;
}

bool ValidateNumberInRange(int Number , int From , int To){
    return (Number >= From && Number <= To) ; // Return True Or False ( cuz  Type IS Bool ) ;
}

void PrintResult(int Age){
    if (ValidateNumberInRange(Age , 18 , 45))
    cout << Age << " Is a Valid age \n" ;
    else
    cout << Age << " Is a Invalid age \n" ;

}

int main(){
    PrintResult(ReadAge());
    return 0 ;
}