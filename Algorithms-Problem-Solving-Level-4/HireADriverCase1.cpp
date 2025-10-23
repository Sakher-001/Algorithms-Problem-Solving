#include <iostream>
#include <string>

using namespace std ;

struct stInfo {
    int Age ;
    bool HasDrivingLicense ;
};

stInfo ReadInfo(){
    stInfo Info ;
    cout << "Please Enter Your Age ? " << endl ;
    cin >> Info.Age ;

    cout << "Do You Have A Driver License ? ";
    cin >> Info.HasDrivingLicense ;
    return Info;
};

bool IsAccepted(stInfo Info){
    return (Info.Age > 21 && Info.HasDrivingLicense);
};


void PrintResult (stInfo Info){
    if (IsAccepted(Info)){
        cout << "\n Hired \n" ;
    }else {
        cout << "\n Rejected \n" ;
    }
}
int main(){
    PrintResult(ReadInfo());
    return 0 ;
}