#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std ; 


int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From; // 10 - 1 + 1 + 10
    return randNum;
}


enum enSelectCharacter {SmallChar , CapitalChar , SpecialChar , Digits };


char GetRandomChar(enSelectCharacter charType){
    switch (charType)
    {
    case enSelectCharacter::SmallChar  :
        return char(RandomNumber(97,122));
        break;
    case enSelectCharacter::CapitalChar :
        return char(RandomNumber(65 , 90));
        break;
    case enSelectCharacter::SpecialChar :
        return char(RandomNumber(33 , 47)) ;
        break;
    case enSelectCharacter::Digits :
        return char(RandomNumber(48 , 57));
        break;        
    default:
        break;
    }
    return '\0' ;
}

int main(){
    srand((unsigned)time(NULL));
    cout << GetRandomChar(enSelectCharacter::CapitalChar) << endl;
    cout << GetRandomChar(enSelectCharacter::Digits) << endl ;
    cout << GetRandomChar(enSelectCharacter::SmallChar) << endl;
    cout << GetRandomChar(enSelectCharacter::SpecialChar) << endl;
}