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


void PrintTheMatrix(int arr[3][3], short Rows, short Cols){
    for (int i = 0; i < Rows; i++)
    {
        for(int j = 0 ; j < Cols ; j++){
            cout << setw(3) << arr[i][j] << "\t" ;
        }
        cout << endl ;
    }
    
}

int main () {
    srand((unsigned)time(NULL));
    int arr[3][3] , Number;
    FillMatrixWithRandomNumber(arr , 3 ,3);
    cout << "Matrix 3 x 3 : " << endl ;
    PrintTheMatrix(arr , 3 ,3);
    cout << "\n Please Enter Number To Check is Exist ? ";
    cin >> Number ; 
    if (IsExist(arr , Number , 3 , 3))
    {
        cout << "\n Number Is Exist :-) \n" ;
    }else{
        cout << "\n Number Is Not Exist :-( \n " ;
    }
    
}