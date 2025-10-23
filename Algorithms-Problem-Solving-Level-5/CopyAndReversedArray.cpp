#include <iostream>
#include <cmath>


using namespace std ; 



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


void PrintArray(int arr[100] , int arrLength){
    for(int i = 0 ; i < arrLength ; i++ )
        cout  << arr[i] <<  " " ;

    cout << "\n" ;
}
void CopyArrayWithReversed(int arrSource[100] , int arrDestination[100] , int arrLength ){
    int CountReverse = arrLength - 1 ;
    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[CountReverse] ; 
        CountReverse-- ; 
        // OR 
        // arrDestination[i] = arrSource[arrLength - 1 - i] ; 
    }
    
}


int main(){
    srand((unsigned)time(NULL));
    int arr[100]  ;
    int arrLength ;
    FillArrayWithRandomNumbers(arr , arrLength);
    int arr2[100] ;
    CopyArrayWithReversed(arr , arr2 , arrLength);
    cout << "\n Array Element : " ;
    PrintArray(arr , arrLength);
    cout << "\n Copied Reversed Array   : " ;
    PrintArray(arr2 , arrLength);
    return 0 ;
}