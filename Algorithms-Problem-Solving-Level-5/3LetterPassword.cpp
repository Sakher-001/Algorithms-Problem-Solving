#include <iostream>
#include <string>
using namespace std ; 


string ReadPassword()
{
    string Password;  
    cout << "Please enter a 3-Letter Password (all capital)?\n"; 
    cin >> Password;  
    return Password;  
}

bool GuessPassword(string OrignalPassWord){
    cout << "\n" ;
    int count = 0 ;
    string Word = "" ;
    for(int i = 65 ; i <= 90 ; i++){
        for(int j = 65 ; j <= 90 ; j++){
            for(int k = 65 ; k <= 90 ; k++){
                count++ ;
                Word += char(i);
                Word += char(j);
                Word += char(k);

                cout << "Trail [" << count <<  "] : " << Word  << endl ;

                if (Word == OrignalPassWord)
                {
                    cout << "\nPassword is " << Word << " \n" ;
                    cout << "Found After " << count  << "Trail(s)\n";
                    return true ;
                }
                Word = "" ;
            }
        }
    }
    return false ;
}

int main(){
    GuessPassword(ReadPassword());
}