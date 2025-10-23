#include <iostream>
#include <string>
using namespace std ;


int ReadNumber();
int CalcFactorial_With_For_loop(int N);
int CalcFactorial_With_While_loop(int N);
int CalcFactorial_With_Do_While_loop(int N);

int main(){
    int N = ReadNumber() ;
    cout << CalcFactorial_With_For_loop(N) << endl;
    cout << CalcFactorial_With_While_loop(N) << endl;
    cout << CalcFactorial_With_Do_While_loop(N) << endl;
    return 0 ;
}

int ReadNumber(){
    int N ;
    cout << "Enter a Number For Factorial? " ;
    cin >> N ;
    return N ;
}
int CalcFactorial_With_For_loop(int N){
    int Factorial = 1 ;
    cout << "Factorial Of " << N << " With For loop : " ; 
    for (int i = 1; i <= N; i++)
    {
        Factorial *= i ;
    }
    return Factorial ;
}


int CalcFactorial_With_While_loop(int N){
    int Factorial = 1 ;
    int i = 1 ;
    cout << "Factorial Of " << N << " With While loop : " ; 
    while (i <= N){
        Factorial *= i ;
        i++ ;
    }
    return Factorial ;
}

int CalcFactorial_With_Do_While_loop(int N){
    int Factorial = 1 ;
    int i = 1 ;
    cout << "Factorial Of " << N << " With Do-While loop : " ; 
    do{
        Factorial *= i ;
        i++ ;
    }while (i <= N);
    return Factorial ;
}