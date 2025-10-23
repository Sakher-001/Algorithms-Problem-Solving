#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std ; 

int RandomNumber(int From, int To){
    cout << rand() << endl;
    int randNum = rand() % (To - From + 1) + From; // 10 - 1 + 1 + 10
    return randNum;
}

int main(){
    srand((unsigned)time(NULL));
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
}