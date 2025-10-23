#include <iostream>
using namespace std ;


int main (){
    int *p ;
    int arr[4] = {10 , 20 , 30 , 40} ;
    for (int i = 0; i < 4; i++)
    {
        p = arr ;
        cout <<  ( p + i )  << endl;
        cout << *( p + i ) << endl ;
    }
}