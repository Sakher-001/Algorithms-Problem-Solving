#include <iostream>
#include <cmath>


using namespace std ; 

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };


int RandomNumber(int From, int To){
    int randNum = rand() % (To - From + 1) + From; // 100 - 1 + 1 + 1
    return randNum;
}


enPrimNotPrime CheckPrime(int Number){ 
    int M = round(Number / 2); 
    if (Number <= 1){
        return enPrimNotPrime::NotPrime;  
    }
    
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;  
    }
    return enPrimNotPrime::Prime;

}

void FillArrayWithRandomNumbers(int arr[100] , int &arrLength){
    cout << "Please Enter Number Of Element : " ;
    cin >> arrLength ;

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1 , 100);
}


void AddArrayElement(int Number , int arr[100] , int& arrLength){
    if (Number % 2 != 0)
    {
        arrLength++;
        arr[arrLength - 1 ] = Number ; 
    }
    
}

void CopyArrayUsingAddArrayElement(int arr[100] , int arr2[100] , int& arr1Length , int& arr2Length){
    for (int i = 0; i < arr1Length; i++)
        if (CheckPrime(arr[i]) == enPrimNotPrime::Prime)
            AddArrayElement(arr[i] , arr2 , arr2Length);
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
    int arr2[100] ,  arr2Length = 0 ;
    FillArrayWithRandomNumbers(arr , arrLength);

    CopyArrayUsingAddArrayElement(arr, arr2, arrLength, arr2Length);


    cout << "\n Random Array Element : " ;
    PrintArray(arr , arrLength);
    cout << "\n Copied Array With Prime Numbers  : " ;
    PrintArray(arr2 , arr2Length);
    return 0 ;
}