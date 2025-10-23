#include <iostream>
#include <string>
using namespace std ; 


void FillArray(int arr[100] , int& arrLength){
    arrLength = 5 ;
    arr[0] = 10 ;
    arr[1] = 20 ;
    arr[2] = 50 ;
    arr[3] = 20 ;
    arr[4] = 10 ;
}

void PrintArray(int arr[100] , int arrLength){
    for(int i = 0 ; i < arrLength ; i++ )
        cout  << arr[i] <<  " " ;

    cout << "\n" ;
}


bool IsPalindorm(int arr[100] , int arrLength){
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[arrLength - 1 - i])
        {
            return false ;
        }
    }
    return true ;
}


int main(){
    int arr[100] , arrLength ;
    FillArray(arr , arrLength);
    cout << "\n Array Element : \n" ;
    PrintArray(arr , arrLength);
    if (IsPalindorm(arr , arrLength))
        cout << "Yes it's a palindorm :-) " ;
    else
        cout << "No it's Not a palindorm :-( " ;
}