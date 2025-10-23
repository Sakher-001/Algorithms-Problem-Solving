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

short Count_Digit(int arr[3][3] ,  int Number ,short Rows , short Cols ){
    int CountNumber =  0 ;
        for (int i = 0; i < Rows; i++){
        for(int j = 0 ; j < Cols ; j++){
            if (arr[i][j] == 0)
            {
                CountNumber++;
            }
            
        }
    }
    return CountNumber ;
}

bool IsSparateMatrix(int arr[3][3] , short Rows , short Cols){
    int MatrixSize = (Rows * Cols)  ;
    return (Count_Digit(arr ,  0 , 3 ,3)) >= MatrixSize / 2 ;  
}

int main () {
    srand((unsigned)time(NULL));
    int arr[3][3] = {{1,2,4} , {0,0,0} , {1,2,3}};
     // FillMatrixWithRandomNumber(arr , 3 ,3);
    cout << "Matrix 3 x 3 : " << endl ;
    PrintTheMatrix(arr , 3 ,3);
    if (IsSparateMatrix(arr , 3 , 3))
        cout << "Yes : It's Sparate Matrix \n";
    else 
        cout << "No : It's Not Sparate Matrix \n";
}