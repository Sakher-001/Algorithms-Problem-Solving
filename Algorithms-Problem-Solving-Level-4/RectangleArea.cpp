#include <iostream>
#include <string>
using namespace std ;

void ReadWidthAndHeight(float& Width , float& Height){
    cout << "Enter The Width? "; 
    cin >> Width;
    cout << "Enter The Height? "; 
    cin >> Height;
};

float RecatngleArea(float Width , float Height){
    return Width * Height ;
};


void PrintRecatngleArea(float Area){
    cout << "The Area Of Recatngle Is : " << Area ;
};

int main(){
    float Width , Height ;
    ReadWidthAndHeight(Width , Height);
    PrintRecatngleArea(RecatngleArea(Width , Height));
    return 0 ;
}