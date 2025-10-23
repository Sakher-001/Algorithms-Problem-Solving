// Sum Of Coulmns

# include <iostream>
# include <string>
# include <iomanip> 

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

int SumOfCols(int arr[3][3] , short Rows , short Cols) {
    int SumOfCols = 0 ; 
    for (int i = 0; i < Rows; i++)
    {
        SumOfCols += arr[i][Cols];  
    }
    return SumOfCols ;
}

void PrintEachSumOfCols(int arr[3][3] , short Rows , short Cols){
    for (int i = 0; i < Rows; i++)
    {
        cout << "Cols Sum " << i + 1 << " = " << SumOfCols(arr , 3 , i) << endl ;
    }
    
}

int main(){
    srand((unsigned)time(NULL));
    int MatrixArr[3][3] ;
    FillMatrixWithRandomNumber(MatrixArr , 3 , 3);
    cout << "Matrix With Random Nums : " << endl ;
    PrintTheMatrix(MatrixArr , 3 ,3) ;
    PrintEachSumOfCols(MatrixArr , 3 , 3) ;
}
