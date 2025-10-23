#include <iostream>
#include <string>

using namespace std ;


void ReadLength(float& length){
    cout << "Enter Length? " ;
    cin >> length ;
};

float CalcAreaCircule(float length){
    return (pow(length , 2)) / (4*3.14) ;
};

void PrintArea(float Area){
    cout << "The Area : " << Area << endl ;
};

int main(){
    float length;
    ReadLength(length);
    PrintArea(CalcAreaCircule(length));
    return 0 ;
}