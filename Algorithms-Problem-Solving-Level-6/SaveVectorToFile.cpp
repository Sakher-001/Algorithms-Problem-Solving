#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std ;

void SaveVectorToFile(string FileName , vector <string> vFileContent) {
    fstream MyFile ;
    MyFile.open(FileName , ios::out);
        if (MyFile.is_open())
        {
            string line ; 
            for(string &line : vFileContent){
                if (line != "")
                {
                    MyFile << line << endl;
                }
                
            }
            
        }
        MyFile.close();
    }


int main (){
    vector <string> vFileContent {"Mohamed" , "Ahmed" , "Ali" , "Sakher"};
    SaveVectorToFile("MyFile.txt" , vFileContent) ;
}