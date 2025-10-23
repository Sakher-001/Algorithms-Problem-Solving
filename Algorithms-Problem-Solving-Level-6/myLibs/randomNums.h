#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std ; 

namespace randomNumbers{
int RandomNumber(int From, int To){
    int randNum = rand() % (To - From + 1) + From; // 10 - 1 + 1 + 10
    return randNum;
}
}