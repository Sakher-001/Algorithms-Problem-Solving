#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std ; 

enum enChoice { Stone = 1, Paper = 2, Seissors = 3 };
enum enGameResult { PlayerWinner = 1 , ComputerWinner = 2 , Draw = 3 };

enChoice GetPlayerChoice (){
	int Choice = 1 ;
	cin >> Choice ;
	return (enChoice)Choice ;
}

int main(){
	srand((unsigned)time(NULL));
	cout << GetPlayerChoice() ;
	return 0 ;
}