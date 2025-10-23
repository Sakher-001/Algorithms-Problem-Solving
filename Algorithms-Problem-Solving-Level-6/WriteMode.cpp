#include <iostream>
#include <fstream>
using namespace std ;
int main(){
    fstream MyFile ;
    MyFile.open("D:\\learnCpp\\course6\\MyFile.txt" , ios::out); // write mode
    if (MyFile.is_open())
    {
        MyFile << "Hello  , " << endl ;
        MyFile << "My Name Is Mohamed Ahmed Ali Sakher " << endl ;
        MyFile << "My Age Is : 19 " ;
        MyFile.close();
    }
    
}