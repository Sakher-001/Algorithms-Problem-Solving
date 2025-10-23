#include <iostream>
#include <string>

using namespace std ;

struct stInfo {
    int Age ;
    bool HasDrivingLicense ;
    bool HasRecommendiation ;
};

stInfo ReadInfo(){
    stInfo Info ;
    cout << "Please Enter Your Age ? " << endl ;
    cin >> Info.Age ;

    cout << "Do You Have A Driver License ? " << endl;
    cin >> Info.HasDrivingLicense ;

    cout << "HasRecommendiation ? " << endl;
    cin >> Info.HasRecommendiation ;
    return Info;
};

bool IsAccepted(stInfo Info){
    if (Info.HasRecommendiation){
        return true ;
    }else{
        return (Info.Age > 21 && Info.HasDrivingLicense);
    }
    
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