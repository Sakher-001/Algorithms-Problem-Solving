#include <iostream>

#include <cmath>

using namespace std ; 

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };


enPrimNotPrime CheckPrime(int Number){
    int M = round(Number / 2) ;
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrimNotPrime::NotPrime ;
    }
    return enPrimNotPrime::Prime ;
}

int RandomNumber(int From, int To){
    int randNum = rand() % (To - From + 1) + From; // 100 - 1 + 1 + 1
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100] , int &arrLength){
    cout << "Please Enter Number Of Element : " ;
    cin >> arrLength ;

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1 , 100);
}



void CopyArrayWithPrimeNumbers(int arrSource[100] , int arrDestination[100] , int arrLength , int &arr2Length){
    int Counter = 0;
    
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::NotPrime || arrSource[i] <= 1)
            continue;
        else{
            arrDestination[Counter] = arrSource[i];
            Counter++ ;
        }
    }
    arr2Length = --Counter ;
    if (Counter == 0){
        cout << "No Prime Numbers ! " ;
    }
    
}

void PrintArray(int arr[100] , int arrLength){
    for(int i = 0 ; i < arrLength ; i++ )
        cout  << arr[i] <<  " " ;

    cout << "\n" ;
}
int main(){
    srand((unsigned)time(NULL));
    int arr[100]  ;
    int arrLength ;
    FillArrayWithRandomNumbers(arr , arrLength);
    int arr2[100] , arr2Length = 0 ;
    CopyArrayWithPrimeNumbers(arr , arr2 , arrLength ,  arr2Length) ;
    cout << "\n Random Array Element : " ;
    PrintArray(arr , arrLength);
    cout << "\n Copy Array With Prime Numbers Only : " ;
    PrintArray(arr2 , arr2Length);
    return 0 ;
}