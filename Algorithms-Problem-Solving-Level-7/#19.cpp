// Min / Max Number in Matrix
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

int MinNumberInMatrix(int arr[3][3] , short Rows , short Cols ){
    int MinNumber = arr[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for(int j = 0 ; j < Cols ; j++){
            if (arr[i][j] < MinNumber)
            {
                MinNumber = arr[i][j] ;
            }
        }
    }
    return MinNumber ;
}

int MaxNumberInMatrix(int arr[3][3] , short Rows , short Cols ){
    int MaxNumber = arr[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for(int j = 0 ; j < Cols ; j++){
            if (arr[i][j] > MaxNumber)
            {
                MaxNumber = arr[i][j] ;
            }
        }
    }
    return MaxNumber ;
}

int main () {
    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixWithRandomNumber(arr , 3 ,3);
    cout << "Matrix 3 x 3 : " << endl ;
    PrintTheMatrix(arr , 3 ,3);
    cout << "Min Number In Matrix :"  << MinNumberInMatrix(arr , 3 ,3) <<endl ;
    cout << "Max Number In Matrix :"  << MaxNumberInMatrix(arr , 3 ,3) <<endl ;
}