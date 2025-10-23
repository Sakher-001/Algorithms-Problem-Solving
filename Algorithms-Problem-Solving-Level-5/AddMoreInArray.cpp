#include <iostream>
#include <string>
using namespace std ; 


int ReadNumber(){
    int Num ; 
    cout << "Enter a Num To Add in Array : " ;
    cin >> Num ;
    return Num ;
}

void AddArrayElement(int Number , int arr[100] , int& arrLength){
    arrLength++;
    arr[arrLength - 1 ] = Number ;
}


void inputUserNumbersInArray(int arr[100] , int& arrLength){
    bool AddMore = true ;
    do
    {
        AddArrayElement(ReadNumber() , arr , arrLength) ;
        cout << "\nDo You Want To Add More Number ? [0]:No , [1]:Yes ? ";
        cin >> AddMore ;
    } while (AddMore);
    
}

void PrintArray(int arr[100] , int arrLength){
    for(int i = 0 ; i < arrLength ; i++ )
        cout  << arr[i] <<  " " ;

    cout << "\n" ;
}

int main(){
    int arr[100] , arrLength = 0 ;
    inputUserNumbersInArray(arr , arrLength);
    cout << "Array Length : " << arrLength << endl ;
    cout << "Array Elemnets : " ;
    PrintArray(arr , arrLength);
}