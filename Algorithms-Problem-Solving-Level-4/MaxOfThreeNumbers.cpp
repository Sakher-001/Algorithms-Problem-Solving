#include <iostream>
#include <string>
using namespace std ;

void ReadNumber(int& A , int& B , int& C ){
    cout << "Enter First Number? " ;
    cin >> A ;
    cout << "Enter Second Number? "  ;
    cin >> B ;
    cout << "Enter Third Number? "  ;
    cin >> C ;
};

int MaxOf3Numbers(int A , int B , int C){
    if (A > B && A > C)
        return A;
    else if (B > A && B > C)
        return B;
    else
        return C ;
};


void PrintResults(int Max){
    cout << "The Max Value is : " << Max << endl;
}
int main(){
    int A, B, C;
    ReadNumber(A , B, C);
    PrintResults(MaxOf3Numbers(A , B , C));
    return 0 ;
}