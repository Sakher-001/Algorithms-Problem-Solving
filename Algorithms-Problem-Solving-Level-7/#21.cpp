
// Fiboncci series With For Loop ;
#include <iostream>
using namespace std;

void PrintFibonacciUsingLoop(short Number) {
    int Prev1 = 0 ,  Prev2 = 1;
    int FebNumber = 0;
    cout << "1     ";
    for (int i = 0; i < Number; i++) {
        FebNumber = Prev1 + Prev2; // 0 + 1 = 1 ;
        cout << FebNumber << "     ";
        Prev1 = Prev2;  // Prev1 = 1 ;
        Prev2 = FebNumber; // Prev2 = 1 ;
    }
}

int main()
{
    PrintFibonacciUsingLoop(10);
}