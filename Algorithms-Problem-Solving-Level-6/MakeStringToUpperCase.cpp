#include <iostream>
#include <cctype>
#include <string>
using namespace std ;


int main(){
    string S1 = "Mohammed" ;
    string S1_TO_Upper ;
    for (int i = 0; i < S1.length(); i++)
    {
        char x ;
        x = toupper(S1[i]) ;
        S1_TO_Upper.push_back(x) ;
    }
    cout << S1_TO_Upper ;}