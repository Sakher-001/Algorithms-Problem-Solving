#include <iostream>
#include <cctype>
using namespace std ;


int main(){
    int CountUpper , CountLower , CountSympol , CountDigits = 0;
    string Pass ;
    do
    {
        cout << "Enter a Password Should Contain (Upper , lower , digit , symbol , length > 8) : " << endl ;
        getline(cin , Pass) ;
    } while (Pass.length() < 8 );
    
    for (int i = 0; i < Pass.length(); i++)
    {
        char letter = Pass[i] ;
        if (isupper(letter) != 0)
        {
            CountUpper++;
        }else if (islower(letter) != 0) {
            CountLower++;
        }else if (isdigit(letter) != 0 ){
            CountDigits++ ;
        }else if (ispunct(letter) != 0){
            CountSympol++;
        }
    }
    if (CountUpper == 0)
        {
            cout << "Pass Should Contain AtLeast One Letter UpperCase" ;
        }else if (CountLower == 0) {
            cout << "Pass Should Contain AtLeast One Letter LowerCase" ;
        }else if (CountDigits == 0 ){
            cout << "Pass Should Contain AtLeast One Digit" ;
        }else if (CountSympol == 0){
            cout << "Pass Should Contain AtLeast One Sympol" ;
        }else {
            cout << " \nThank You :) \n" ;
        }
        }