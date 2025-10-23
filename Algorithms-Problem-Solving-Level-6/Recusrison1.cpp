#include <iostream>
#include <cmath>
using namespace std ; 

void PrintNumsFrom_M_DownTo_N(int M , int N) {
    if (N <= M)
    {
        cout << M << endl;
        PrintNumsFrom_M_DownTo_N(M - 1 , N) ;
    }
}

int main(){
    PrintNumsFrom_M_DownTo_N(10 , 1);
}