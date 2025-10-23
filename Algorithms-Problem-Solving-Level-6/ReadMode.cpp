#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

void PrintFileContent(string FileName){
    fstream MyFile ;
    MyFile.open("MyFile.txt" , ios::in); // write mode
    if (MyFile.is_open())
    {
        string line ; 
        while (getline(MyFile , line))
        {
            cout << line  << endl ;
        }
        
        MyFile.close();
    }
}

int main(){
    PrintFileContent("MyFile.txt");
}