#include <iostream>11
#include <string>

using namespace std ;

int ReadNumber(){
    int Num ;

    cout << "Enter A Number ? " << endl ;
    cin >> Num ;
    return Num ;
};

float CalculateHalfNum(int Num){
    return (float)Num / 2 ; // Return => return integar Number ;
};

void PrintResult(int Num){
    string Result  = "Half of " + to_string(Num) + " is " + to_string(CalculateHalfNum(Num));
    cout << endl << Result << endl ;
};

int main(){
    PrintResult(ReadNumber());
    return 0 ;
}