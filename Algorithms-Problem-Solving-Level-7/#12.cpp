// Random Matrix 3 x 3 ;

#include <iostream>
#include <string>
#include <iomanip>



using namespace std ; 



int RandomNumber(int From, int To){
    int randNum = rand() % (To - From + 1) + From; 
    return randNum;
}

void FillMatrixWithRandomNumber(int arr[3][3] , short Rows , short Cols){
    for (int i = 0; i < Rows; i++)
    {
        for(int j = 0 ; j < Cols ; j++){
            arr[i][j] = RandomNumber(1 , 100);
        }
        cout << endl ;
    }
}

void PrintTheMatrix(int arr[3][3], short Rows, short Cols){
    for (int i = 0; i < Rows; i++)
    {
        for(int j = 0 ; j < Cols ; j++){
            cout << setw(3) << arr[i][j] << "\t" ;
        }
        cout << endl ;
    }
    
}


bool IsMatrixEQuals(int arr[3][3], int arr2[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (arr[i][j] != arr2[i][j]) {
                return false;   
            }
        }
    }
    return true;
}


void PrintCheckResult(int arr[3][3] , int arr2[3][3] , short Rows , short Cols){
    if (IsMatrixEQuals(arr , arr2 , 3 ,3) )
        cout << "The Matrix IS Equals " << endl ;
    else 
        cout << "The Matrix IS Not Equals " << endl ;    
}

int main () {
    srand((unsigned)time(NULL));
    int arr[3][3] , arr2[3][3];
    FillMatrixWithRandomNumber(arr , 3 ,3);
    cout << "Matrix 3 x 3 (1) : " << endl ;
    PrintTheMatrix(arr , 3 ,3);
    FillMatrixWithRandomNumber(arr2 , 3 ,3);
    cout << "Matrix 3 x 3 (2) : " << endl ;
    PrintTheMatrix(arr2 , 3 ,3);
    PrintCheckResult(arr ,arr2 , 3 , 3);
}