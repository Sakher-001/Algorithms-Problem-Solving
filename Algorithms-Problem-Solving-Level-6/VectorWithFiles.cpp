#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std ;

void ReadDataFromFile(string FileName , vector <string> & vFileContent){
    fstream MyFile ; 
    MyFile.open(FileName , ios::in) ;
    if (MyFile.is_open()){
        string line ; 
        while(getline(MyFile , line)){
            vFileContent.push_back(line) ;
        }
        MyFile.close();
    }
}

int main(){
    vector <string> vFileContent ;
    ReadDataFromFile("MyFile.txt" , vFileContent); 
    for (int i = 0 ; i < vFileContent.size() ; i++ ){
        cout << vFileContent[i] << endl ;
    }
    return 0 ;
}