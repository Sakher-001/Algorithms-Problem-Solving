#include <iostream>
#include <string>
using namespace std ;

enum enOddOrEven {odd = 1 , even = 2};

enOddOrEven CheckOddOrEven(int Number){
    return Number % 2 == 0 ? enOddOrEven::even : enOddOrEven::odd ; 
}

int ReadNumber(){
    int N ;
    cout << "Please Enter Number? " ;
    cin >> N ;
    return N ;
}


int sumOddWith_for_loop(int N){
    int Sum = 0 ;
    cout << "Sum Odd Numbers using for Statement: " ;
    for (int i = 1; i <= N; i++)
    {
        if (CheckOddOrEven(i) == enOddOrEven::odd)
        {
            Sum += i ;
        }
    }
        return Sum ;
    
};

int sumOddWith_While_loop(int N){
    int Sum = 0 ;
    cout << "Sum Odd Numbers using While Statement: " ;
    int i = 1 ;
    while (i <= N){
        if (CheckOddOrEven(i) == enOddOrEven::odd)
            Sum += i ;
        i++ ;
    }
    return Sum ;
}

int sumOddWith_Do_While_loop(int N){
    int Sum = 0 ;
    int i = 1 ;
    cout << "Sum Odd Numbers using Do-While Statement: " ;
    do
    {
        if (CheckOddOrEven(i) == enOddOrEven::odd)
        {
            Sum += i ;
        }
        i++ ;
    } while (i <= N);
    return Sum ;
}

int main(){
    int N = ReadNumber();
    cout << sumOddWith_for_loop(N) << endl;
    cout << sumOddWith_While_loop(N) << endl;
    cout << sumOddWith_Do_While_loop(N) << endl;
    return 0 ;
}