#include <iostream>



using namespace std ; 

int SearchNum(string Message){
    int Number = 0;  
    do
    {
        cout << Message << endl;  
        cin >> Number;            
    } while (Number <= 0);         

    return Number;  
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


void PrintArray(int arr[100] , int arrLength){
    for(int i = 0 ; i < arrLength ; i++ )
        cout  << arr[i] <<  " " ;

    cout << "\n" ;
}

void SearchInArray(int arr[100] , int arrLength){
    int Num = SearchNum("Please Enter Num For Search In Array : ");
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Num)
        {
            cout << "Number You are Looking for is : " << arr[i] << endl  ;
            cout << "The number is  found :-) \n";
            return;
        }
    }
        cout << "Number you are looking for is = " << Num << endl;
        cout << "The number is not found :-( \n";
}

int main(){
    srand((unsigned)time(NULL));
    int arr[100]  ;
    int arrLength ;
    FillArrayWithRandomNumbers(arr , arrLength);
    cout << "\n Random Array Element : " ;
    PrintArray(arr , arrLength);
    SearchInArray(arr  ,arrLength);
    return 0 ;
}