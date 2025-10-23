#include <iostream>
#include <cstdio>

using namespace std ;


int main(){
    int x[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((i + 1)*(j + 1) < 10){
                x[i][j] = ( i + 1 ) * ( j + 1 ) ;
                printf("%02d " , x[i][j]);
            }
            else{
                x[i][j] = ( i + 1 ) * ( j + 1 ) ;
                cout << x[i][j] << " " ;
            }
        }
        cout << endl ;
    }
}