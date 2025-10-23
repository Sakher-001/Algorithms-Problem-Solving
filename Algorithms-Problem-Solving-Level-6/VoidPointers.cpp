#include <iostream>
using namespace std ;

int main(){
    void *ptr  ;
    float f1 = 10.5 ;
    int x = 10 ; 
    string name = "Mohammed" ;
    ptr = &f1 ;
    cout << ptr << endl ; 
    cout << *(static_cast<float *>(ptr)) << endl ;
    ptr = &x ; 
    cout << ptr << endl ;
    cout << *(static_cast<int*>(ptr)) ;
    ptr = &name ;
    cout << ptr <<endl ; 
    cout << *(static_cast<string*>(ptr)) ;
}