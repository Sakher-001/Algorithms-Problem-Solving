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

int SumOfMatrix(int arr[3][3] , short Rows , short Cols){
    int SumOfRows = 0 ; 
    for (int i = 0; i < Cols; i++)
    {
        SumOfRows += arr[Rows][i];
    }
    return SumOfRows ;
}

void EachRowsSum(int arr[3][3] , int NewArray[3] , short Rows , short Cols) {
    for (short i = 0; i < Rows; i++)
    {
        NewArray[i] = SumOfMatrix(arr , i , Cols) ; 
    }
    
}

void PrintSumOfArray(int arr[3] , short length){
    for (int  i = 0; i < length; i++)
    {
        cout << " Rows " << i + 1 << " = " <<  arr[i] << endl ;
    }
    
}

int main () {
    srand((unsigned)time(NULL));
    int arr[3][3];
    int CopySumArr[3] ;
    FillMatrixWithRandomNumber(arr , 3 ,3);
    cout << "Matrix 3 x 3 : " << endl ;
    PrintTheMatrix(arr , 3 ,3);
    cout << endl << endl ;
    cout << "The followin Is The Sum Of 3x3 Matrix : " << endl ; 
    EachRowsSum(arr , CopySumArr , 3 , 3);
    PrintSumOfArray(CopySumArr , 3) ;
}