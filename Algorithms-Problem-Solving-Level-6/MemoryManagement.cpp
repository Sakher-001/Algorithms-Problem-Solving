#include <iostream>
using namespace std ;
int main(){
    int *ptrX ;
    float *ptrY ;
    string *ptrZ ;
    
    ptrX = new int ; 
    ptrY = new float ;
    ptrZ = new string ;

    *ptrX = 45 ;
    *ptrY = 58.35f ; 
    *ptrZ = "Mohamed" ;
    cout << *ptrX << endl ;
    cout << *ptrY << endl ;
    cout << *ptrZ << endl ;  
    delete ptrX ;
    delete ptrY ;
    delete ptrZ ; 
}