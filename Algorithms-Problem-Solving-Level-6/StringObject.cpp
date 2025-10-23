#include <iostream>
#include <string>
using namespace std ;
int main(){
    string S1 = "My Name is Mohamed Ahmed Ali Sakher , I Love Programming." ;

    //Print Length Of String ;
    cout << S1.length() << endl ;
    // Return The Current Element With Index ;
    cout << S1.at(3) << endl ;
    // Add String AT The End ; 
    cout << S1.append(" @ProgrammingAdvice") << endl ;
    // insert new Value at Position ;
    cout << S1.insert(7 , "Mona") << endl;
    // Cut String with SubStr ;
    cout << S1.substr(16 , 8 )<< endl;
    // Search in String ;
    cout << S1.find("Ali")<< endl;  // caseSensivte
    cout << S1.find("ali") << endl;
    if (S1.find("ali") == S1.npos)
    {
        cout << "ali is not Found "<< endl ;
    }
    S1.clear() ;
    cout << S1 ;
}