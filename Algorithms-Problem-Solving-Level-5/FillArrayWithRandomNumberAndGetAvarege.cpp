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

float AverageNumber(int arr[100] , int arrLength){
    int Sum = 0 ;
    float Average ;
    for (int i = 0; i < arrLength; i++)
    {
        Sum += arr[i] ;
    }
    Average = Sum / float(arrLength) ;
    return float(Average) ;
}

int main(){
    srand((unsigned)time(NULL));
    int arr[100]  ;
    int arrLength ;
    FillArrayWithRandomNumbers(arr , arrLength);
    cout << "\n Random Array Element : " ;
    PrintArray(arr , arrLength);
    cout << "Average Number in The Array : " << AverageNumber(arr ,arrLength)  << endl;
    return 0 ;
}