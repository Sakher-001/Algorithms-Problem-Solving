#include <iostream> 
#include <vector> 
using namespace std ;

struct stEmployee {
string FirstName ;
string LastName  ;
int Salary ;
};


void ReadEmployee (vector <stEmployee> & vEmployees ){
    stEmployee TempEmployee ;
    string FirstName ;
    string LastName ;
    int Salary ;
    char ReadMore ;
    do
    {
        cout << "Enter Your First Name : " ;
        cin >> FirstName ;
        TempEmployee.FirstName = FirstName ;
        cout << "Enter Your Last Name : " ;
        cin >> LastName ; 
        TempEmployee.LastName = LastName ;
        cout << "Enter Your Salary : " ;
        cin >> Salary ;
        TempEmployee.Salary = Salary ;
        vEmployees.push_back(TempEmployee) ;
        cout << "\nDo You Want To Add Employee ? Y|N : \n\n" ;
        cin >> ReadMore ;
    } while (ReadMore == 'Y' || ReadMore == 'y' );
}

void PrintVectorNumbers(vector <stEmployee> & vEmployees ){
    cout << "Vector Employees : \n\n" ;
    for(stEmployee TempEmployee  : vEmployees){
        cout << "First Name : " << TempEmployee.FirstName << endl;  
        cout << "Last Name : " << TempEmployee.LastName << endl;  
        cout << "Salary : " << TempEmployee.Salary << endl << endl << endl;  
    }
}

int main () {
    vector <stEmployee>  vEmployees ;
    ReadEmployee(vEmployees);
    PrintVectorNumbers(vEmployees);
}