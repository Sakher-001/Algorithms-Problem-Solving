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


void ReadArray(int arr[100] , int& arrLength){
    cout << "Please Enter Number Of Element : " ;
    cin >> arrLength ;
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element["<< i + 1 <<"] : " ;
        cin >> arr[i];
    }
}

void PrintArray(int arr[100] , int arrLength){
    string OriginalNum = "" ;
    for(int i = 0 ; i < arrLength ; i++ ){
        OriginalNum += to_string(arr[i]) ;
    }
    cout << "Original array : " << OriginalNum ;
    cout << "\n" ;
}


int TimesRepeated(int Number , int arr[100] , int arrLength){
    int count = 0 ;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            count++;
    }
    return count ;
}

int main(){
    int arr[100] , arrlength , NumberToCheck ;
    ReadArray(arr , arrlength) ;
    PrintArray(arr , arrlength); 
    NumberToCheck = ReadPositiveNumber("Please Enter Number To check : ") ;
    cout << NumberToCheck << " is repeated " << TimesRepeated(NumberToCheck , arr , arrlength) << " Time(s)" << endl;
}
