#include <iostream>
#include <iomanip>

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

bool CheckMatrixIdentity(int arr[3][3] , short Rows , short Cols){
    for (int i = 0; i < Rows; i++){
        for(int j = 0 ; j < Cols ; j++){
            if (i == j && arr[i][j] != 1 )
            {
                return false ;
            }else if (i != j && arr[i][j] != 0 ){
                return false ;
            }
            
        }
    }
    return true ;
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
    int arr[3][3] = {{0,0,1} , {0,1,0} , {1,0,0}};
    // FillMatrixWithRandomNumber(arr , 3 ,3);
    cout << "Matrix 3 x 3 : " << endl ;
    PrintTheMatrix(arr , 3 ,3);

    if (CheckMatrixIdentity(arr , 3 , 3))
        cout << "\nMatrix Is Identity\n" ;
    else 
        cout << "\nMatrix Is Not Identity\n" ;
}