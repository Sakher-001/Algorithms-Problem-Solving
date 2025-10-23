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

bool IsExist(int arr[3][3] , int Number , short Rows , short Cols){
    for (int i = 0; i < Rows; i++)
    {
        for(int j = 0 ; j < Cols ; j++){
            if (arr[i][j] == Number)
            {
                return true ;
            }
        }
    }
    return false ;
}

void IntersectedMatrix(int arr1[3][3] , int arr2[3][3], short Rows , short Cols){
    int Number ;
    for (int i = 0; i < Rows; i++)
    {
        for(int j = 0 ; j < Cols ;  j++){
            Number = arr1[i][j] ;
            if (IsExist(arr2  , Number , 3 , 3))
            {
                cout << setw(3) << Number ;
            }
            
        }
    }
    
}

int main () {
    srand((unsigned)time(NULL));
    int arr[3][3] , arr2[3][3];
    FillMatrixWithRandomNumber(arr , 3 ,3);
    cout << "Matrix 3 x 3 (1): " << endl ;
    PrintTheMatrix(arr , 3 ,3);
    FillMatrixWithRandomNumber(arr2 , 3 ,3);
    cout << "Matrix 3 x 3 (2): " << endl ;
    PrintTheMatrix(arr2 , 3 ,3);
    cout << "The intersected in 2 Matrix Is : \n" ;
    IntersectedMatrix(arr , arr2 , 3 , 3);
}