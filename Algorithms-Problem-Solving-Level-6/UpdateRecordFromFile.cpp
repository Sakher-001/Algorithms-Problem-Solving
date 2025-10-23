#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std ;

void PrintFileContent(string fileName){
    fstream MyFile ;
    MyFile.open(fileName , ios::in);
    if (MyFile.is_open())
    {
        string line ; 
        while (getline(MyFile , line))
        {
            cout << line << endl ;
        }
        MyFile.close();
    }
}

void loadDataFromFileToVector(string fileName , vector <string> &vFileContent){
    fstream MyFile ; 
    MyFile.open(fileName , ios::in) ;
    if (MyFile.is_open())
    {
        string line ; 
        while(getline(MyFile , line)){
            vFileContent.push_back(line) ;
        }
        MyFile.close();
    }
    
}

void SaveDataFromVectorToFile(string fileName , vector <string> & vfileContent ){
    fstream MyFile ; 
    MyFile.open( fileName, ios::out) ; 
    if (MyFile.is_open())
    {
        string line ; 
            for(string &line : vfileContent){
                if (line != "")
                {
                    MyFile << line << endl;
                }
                
            }
            MyFile.close();
    }
    
}


void UpdateRecordFromFile(string fileName , string Record , string UpdateTo){
    vector <string> vFileContent ; 
    loadDataFromFileToVector(fileName , vFileContent);
    for(string &line : vFileContent ){
        if (line == Record)
        {
            line =  UpdateTo ;
        }
    }
    SaveDataFromVectorToFile(fileName , vFileContent) ;
}

int main (){
    cout << "File Before Deleting : " << endl ;
    PrintFileContent("MyFile.txt");
    cout << "File After Updating The Record : " << endl  ;
    UpdateRecordFromFile("MyFile.txt" , "Omar" , "Mohamed" );
    PrintFileContent("MyFile.txt");
}