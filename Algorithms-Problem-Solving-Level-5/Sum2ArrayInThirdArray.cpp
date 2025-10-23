#include <iostream>
#include <string>
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


void FillArrayWithRandomNumbers(int arr[100] , int arrLength){
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1 , 100);
}

void SumOf2Arrays(int arr[100] , int arr2[100] , int Sum[100] , int arrLength){
    int count = 0 ;
    for (int i = 0; i < arrLength; i++)
        {Sum[count] = arr[i] + arr2[i] ; 
        count++ ;}
}


void PrintArray(int arr[100] , int arrLength){
    for(int i = 0 ; i < arrLength ; i++ )
        cout  << arr[i] <<  " " ;

    cout << "\n" ;
}

int main(){
    srand((unsigned)time(NULL));
    int arr[100]  ,  arr2[100] ,  arrSum[100] , arrLength ;
    arrLength = ReadPositiveNumber("Please Enter a Postive Number : ") ;
    FillArrayWithRandomNumbers(arr , arrLength);
    FillArrayWithRandomNumbers(arr2 , arrLength);
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 elements:\n";
    PrintArray(arr2, arrLength);
    cout << "\nSum Of 2 Arrays :\n" ;
    SumOf2Arrays(arr, arr2, arrSum, arrLength);
    PrintArray(arrSum , arrLength);
}