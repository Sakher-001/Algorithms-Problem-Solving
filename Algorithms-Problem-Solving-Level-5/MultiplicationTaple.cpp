#include <iostream>
using namespace std ;

void PrintTapleHeader(){
    cout << "\n\n\t\t\t Multipliaction Taple From 1 To 10\n\n" ;
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t" ;
    }
        cout << "\n___________________________________________________________________________________\n";
}

string CoulmSperator(int i){
    if (i < 10){
        return "   |" ;
    }else {
        return "  |" ;
    }
}


void PrintMultiplicationTable(){
    PrintTapleHeader();

    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << CoulmSperator(i) << "\t";
        for (int j = 1; j <= 10 ; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl ;
    }
    
}

int main(){
    PrintMultiplicationTable();
}