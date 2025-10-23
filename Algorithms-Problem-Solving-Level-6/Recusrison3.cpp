#include <iostream>
#include <cmath>
using namespace std ; 

void PrintEvenNumsFrom_M_To_N(int M , int N) {
    if (M <= N)
    {
        if (M % 2 == 0)
        {
            cout << M << endl;
            PrintEvenNumsFrom_M_To_N(M + 2 , N) ;
        }
        else{
            M += 1 ;
            PrintEvenNumsFrom_M_To_N(M + 2 , N);
        }
    }
}

int main(){
    PrintEvenNumsFrom_M_To_N(2 , 10);
}