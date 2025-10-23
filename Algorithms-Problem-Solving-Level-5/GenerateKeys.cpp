#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std ; 

int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message << endl; 
        cin >> Number;           
    } while (Number <= 0);       
    
    return Number; 
}

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

string GenerateWord(enSelectCharacter charType , short length){
    string word ;
    for (int i = 0; i <= length; i++)
    {
        word += GetRandomChar(charType) ;
    }
    return word ;
}

string GenerateKey(){
    string Key = "" ;
    Key = GenerateWord(enSelectCharacter::CapitalChar , 4) + "-";
    Key += GenerateWord(enSelectCharacter::CapitalChar , 4) + "-";
    Key += GenerateWord(enSelectCharacter::CapitalChar , 4) + "-";
    Key += GenerateWord(enSelectCharacter::CapitalChar , 4) ;
    return Key ;
}

void GenerateKeys(short NumberOfKeys){
    int count = 0 ;
    for (int i = 0; i < NumberOfKeys; i++)
    {
        count++ ;
        cout << "Key["<< count <<"] " << GenerateKey() << endl ;
    }
    
}

int main(){
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Please Enter a Postive Number : "));
}