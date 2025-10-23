# include <iostream>
# include <string>
# include <iomanip>

using namespace std ;

void FillMatrixArrayWithOrderedNumber(int arr[3][3] , short Rows , short Cols) {
    short Counter = 1; 
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = Counter;
            Counter++;
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

void TransposedMatrix(int arr[3][3] ,int arrTransposed[3][3] , short Rows , short Cols ){

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arrTransposed[i][j] = arr[j][i];
        }
    }
    
}

int main (){
    int MatrixArr[3][3]  , arrTransposed[3][3];
    FillMatrixArrayWithOrderedNumber(MatrixArr , 3 , 3);
    cout<<"MatrixArrayWithOrderedNumber : " << endl << endl ;
    PrintTheMatrix(MatrixArr , 3 ,  3);
    TransposedMatrix(MatrixArr , arrTransposed , 3 , 3) ;
    cout << endl << "Transposed Matrix : " << endl ;
    PrintTheMatrix(arrTransposed , 3, 3);
}