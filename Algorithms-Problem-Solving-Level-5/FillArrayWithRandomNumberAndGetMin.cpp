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

int MinNumber(int arr[100] , int arrLength){
    int Min = arr[0] ;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    return Min ;
}

int main(){
    srand((unsigned)time(NULL));
    int arr[100]  ;
    int arrLength ;
    FillArrayWithRandomNumbers(arr , arrLength);
    cout << "\n Random Array Element : " ;
    PrintArray(arr , arrLength);
    cout << "Min Number in The Array : " << MinNumber(arr ,arrLength)  << endl;
    return 0 ;
}