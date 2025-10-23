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
            arr[i][j] =  RandomNumber(1 , 10);
        }
        cout << endl ;
    }
}


void MultiplyTwoMatrix(int arr1[3][3],int arr2[3][3],int arr3[3][3] , short Rows , short Cols){
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr3[i][j] = arr1[i][j] * arr2[i][j];
        }
        
    }
    
}

void PrintTheMatrix(int arr[3][3], short Rows, short Cols){
    for (int i = 0; i < Rows; i++)
    {
        for(int j = 0 ; j < Cols ; j++){
            cout << setw(2) << setfill('0') << arr[i][j] << "\t" ;
        }
        cout << endl ;
    }
    
}
int main () {
    srand((unsigned)time(NULL));
    int arr1[3][3];
    int arr2[3][3];
    int arr3[3][3];
    FillMatrixWithRandomNumber(arr1 , 3 ,3);
    FillMatrixWithRandomNumber(arr2 , 3 , 3);
    cout << "Matrix 3 x 3 : (1)" << endl ;
    PrintTheMatrix(arr1 , 3 ,3);
    cout << "Matrix 3 x 3 : (2)" << endl ;
    PrintTheMatrix(arr2 , 3 ,3) ;
    cout << "Matrix 3 x 3 : (3)" << endl ;
    MultiplyTwoMatrix(arr1 , arr2 , arr3 , 3 , 3);
    PrintTheMatrix(arr3 , 3 ,3);
}