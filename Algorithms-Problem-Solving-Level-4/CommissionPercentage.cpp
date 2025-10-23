#include <iostream>
#include <string>
using namespace std ;

double ReadNumber(){
    double TotalSales ;
    cout << "Enter Your Total Sales? " ;
    cin >> TotalSales ;
    return TotalSales ;
}

float CalcPrecentage(float TotalSales){
    if (TotalSales >= 1000000){
        return TotalSales * (1/100) ;
    }else if (TotalSales >= 500000){
        return TotalSales * (2/100) ;
    }else if(TotalSales >= 100000){
        return TotalSales * (3/100) ;
    }else if(TotalSales >= 50000){
        return TotalSales * (5/100) ;
    }else{
        return TotalSales ;
    }
}

int main(){
    cout << CalcPrecentage(ReadNumber());
    return 0 ;
}