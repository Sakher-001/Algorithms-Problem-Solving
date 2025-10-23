#include <iostream>
#include <string>
using namespace std ;

int ReadNumber(){
    int Number ; 
    cout << "Please Enter A Number? " ;
    cin >> Number ;
    return Number ;
}

int ReadPower(){
    int Number;
    cout << "Please Enter The Power? ";
    cin >> Number ;
    return Number ;
}

int PowerOfM(int Number , int M){
    if(M == 0){
        return 1 ;
    }

    int P = 1 ;
    for (int i = 1; i <= M ; i++)
    {
        P = P * Number ;
    }
    return P ;
}

void PrintResult(int Result){
    cout << "Result = " << Result ;
}
int main(){
    PrintResult(PowerOfM(ReadNumber() , ReadPower()));
    return 0 ;
}