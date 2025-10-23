#include <iostream> 
#include <vector> 
using namespace std ;


void ReadNumber (vector <int> & vNumbers){
    int Number = 0 ;
    char IsYes ;
    do
    {
        cout << "Please Enter a Number : " ;
        cin >> Number ;
        vNumbers.push_back(Number);
        cout << "\nDo You Want To Add More Number ? Y/N" << endl;
        cin >> IsYes ;
    } while (IsYes == 'Y' || IsYes == 'y' );
    
}

void PrintVectorNumbers(vector <int> & vNumber){
    for(int Number : vNumber){
        cout << "Numbers Vector : " <<  Number  << endl ;
    }
}

int main () {
    vector <int> vNumbers;
    ReadNumber(vNumbers);
    PrintVectorNumbers(vNumbers);
}