
// Print Febioncci Series With recuresion ;
#include <iostream>
using namespace std;
void PrintFibonacciUsingRecurssion(short Number , int Prev1 , int Prev2) {
	int FebNumber = 0;
	if (Number > 0)
	{
		FebNumber = Prev1 + Prev2;
		cout  << FebNumber << "      ";
		Prev1 = Prev2; 
		Prev2 = FebNumber; 
	PrintFibonacciUsingRecurssion(Number - 1 , Prev1 , Prev2);
	}
}

int main()
{
	cout << "1      ";
	PrintFibonacciUsingRecurssion(10 , 0 , 1);
}