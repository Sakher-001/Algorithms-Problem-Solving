#include <iostream>
#include <ctime>

using namespace std ;

int main () {
    time_t TimeNow = time(0) ;
    tm *LocalTime =  localtime(&TimeNow);
    cout << asctime(LocalTime);
    cout << "Hour : "    << LocalTime->tm_hour << endl; 
    cout << "Minutes : " << LocalTime->tm_min  << endl;
    cout << "Seconds : " << LocalTime->tm_sec  << endl;
    // التحويل للنظام العالمي
    tm *UtcTime = gmtime(&TimeNow) ;
    cout << asctime(UtcTime);
    cout << "General Hour Time : " << UtcTime->tm_hour << endl ;
    cout << "General Minute Time : " << UtcTime->tm_min << endl ;
    cout << "General Second Time : " << UtcTime->tm_sec << endl ;

    cout << "Time Diffrence : " << endl << "Hours Diffrence : " << LocalTime->tm_hour - UtcTime->tm_hour  << endl << "Minutes Diffrence : " << LocalTime->tm_min - UtcTime->tm_min << endl; 

}