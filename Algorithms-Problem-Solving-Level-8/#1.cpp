#include <iostream>
#include <string>
using namespace std;

int  ReadNum() {
	int Num;
	cout << "Please Enter a Number To Transfer To Text : ";
	cin >> Num;
	return Num;
}

string ConvertNumberToText(int Num) {
	if (Num == 0)
	{
		return "";
	}
	if (Num >= 1 && Num <= 19)
	{
		string arr[] = {
			"" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" ,"Eight" , "Nine" , "Ten" ,
			"Eleven" , "Tweleve" , "Thirteen" , "Fourteen" , "Fiveteen" , "Sixteen" , "Seventeen",
			"Eighteen" , "Nineteen"
		};
		return arr[Num] + " ";
	}if (Num >= 20 && Num <= 99)
	{
		string arr[] = {
			"" , "" , "Twenty" , "Thirty" , "Fourty" , "Fivty" ,
			"Sixty" , "Seven" , "Eighty" , "Nintey"
		};
		return arr[Num / 10] + "-" + ConvertNumberToText(Num % 10);
	}
	if (Num >= 100 && Num <= 199) {
		
		return  "One Hundered " + ConvertNumberToText(Num % 100);
	}	
	if (Num >= 200 && Num <= 999) {
		return ConvertNumberToText(Num / 100) + " Hundered " + ConvertNumberToText(Num % 100);
	}
	if (Num >= 1000 && Num <= 1999)
	{
		return "One Thousand " + ConvertNumberToText(Num % 1000);
	}
	if (Num >= 2000 && Num <= 999999) {
		return ConvertNumberToText(Num / 1000) + " Thousand " + ConvertNumberToText(Num % 1000);
	}
	if (Num >= 1000000 && Num <= 1999999)
	{
		return "One Million " + ConvertNumberToText(Num % 1000000);
	}
	if (Num >= 2000000 && Num <= 999999999)
	{
		return ConvertNumberToText(Num / 1000000) + " Millions " + ConvertNumberToText(Num % 1000000);
	}
	if (Num >= 1000000000 && Num <= 1999999999)
	{
		return "One Billion " + ConvertNumberToText(Num % 1000000000);
	}
	if (Num >= 2000000000 && Num <= 9999999999)
	{
		return ConvertNumberToText(Num / 1000000000) + " Billions " + ConvertNumberToText(Num % 1000000000);
	}
}

int main()
{
	int Num = ReadNum();
	cout << ConvertNumberToText(Num);
}
