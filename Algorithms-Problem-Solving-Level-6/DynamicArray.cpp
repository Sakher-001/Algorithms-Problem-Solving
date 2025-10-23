// Dynamic Array Using Pointers ;
#include <iostream> 
using namespace std ; 


int main(){
    int num  ;
    cout << "Enter Total Number Of Students " ;
    cin >> num ;

    float *ptr ;

    ptr = new float[num] ;
    cout << "Enter Grades Of Students "  << endl ;
    for (int i = 0; i < num; i++)
    {
        cout << "Student" << i + 1 << ": " ;
        cin >> *(ptr + i);
    }
    cout << "\nDisplaying grades of students\n" ;
    for (int i = 0; i < num; i++)
    {
        cout << "Students " << i + 1   << ": " << *( ptr + i ) << endl ;
    }
    delete [] ptr ;

    return 0 ;
}