#include <iostream>
#include <string>
using namespace std ; 

void Swap(int& A , int& B){
    int Temp = A ;
    A = B ;
    B = Temp ;
}

int ReadPositiveNumber(string Message){
    int Number = 0;  
    do
    {
        cout << Message << endl;  
        cin >> Number;            
    } while (Number <= 0);         

    return Number;  
}



void FillArrayWithRandomNumbers(int arr[100] , int arrLength){
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}



int RandomNumber(int From, int To){
    int randNum = rand() % (To - From + 1) + From; // 100 - 1 + 1 + 1
    return randNum;
}

void ShuffleArray(int arr[100] , int arrLength){
    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[RandomNumber(1 , arrLength) - 1] , arr[RandomNumber(1 , arrLength) - 1]);
    }
    
}

void PrintArray(int arr[100] , int arrLength){
    for(int i = 0 ; i < arrLength ; i++ )
        cout  << arr[i] <<  " " ;

    cout << "\n" ;
}

int main(){
    srand((unsigned)time(NULL));

    int arr[100];  
    int arrLength = ReadPositiveNumber("\nEnter number of elements : \n");

    
    FillArrayWithRandomNumbers(arr, arrLength);

    
    cout << "\nArray elements before shuffle:\n";
    PrintArray(arr, arrLength);
    
    
    ShuffleArray(arr, arrLength);

    
    cout << "\nArray elements after shuffle:\n";
    PrintArray(arr, arrLength);

    return 0;  
}