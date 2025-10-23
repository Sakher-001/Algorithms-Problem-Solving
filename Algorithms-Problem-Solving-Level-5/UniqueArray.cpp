#include <iostream>
#include <string>
using namespace std ; 

void FillArray(int arr[100] , int& arrLength){
    arrLength = 10 ;
    arr[0] = 10 ;
    arr[1] = 10 ;
    arr[2] = 10 ;
    arr[3] = 50 ;
    arr[4] = 50 ;
    arr[5] = 70 ;
    arr[6] = 70 ;
    arr[7] = 70 ;
    arr[8] = 70 ;
    arr[9] = 90 ;
}


void CopyUniqeValues(int arr[100] , int arr2[100] , int arrLength , int& arr2Lentgh){
    int count = 0 ;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[i + 1]) 
        {
            arr2[count] = arr[i] ; 
            count++; 
            arr2Lentgh++; 
        }
    }
    
}

void PrintArray(int arr[100] , int arrLength){
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " " ;
    }
    
}
int main(){
    int arr[100] , arr2[100] , arrLength ;
    int arr2Length = 0 ;
    FillArray(arr , arrLength);
    cout << "\n Array Element : \n" ;
    PrintArray(arr , arrLength);
    cout << "\n Unique Numbers : \n" ;
    CopyUniqeValues(arr , arr2 , arrLength , arr2Length);
    PrintArray(arr2 , arr2Length);
}