#include <iostream> 
#include <vector>
using namespace std ;

int main(){
    vector<int> num{1 , 2 , 3 , 4 , 5} ;
    // cout << num.at(5) ; // make Error (Programm Crash) ;
    try
    {
        cout << num.at(5) ;
    }
    catch(...)
    {
        cout << "Out Of Bound" ;
    }
    
}