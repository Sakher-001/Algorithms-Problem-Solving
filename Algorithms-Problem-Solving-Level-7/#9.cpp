#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int from, int to)
{
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}
void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d ", 2, arr[i][j]);
		}
		cout << endl; 
	}
}
void PrintMiddleRowOfMatrix(int arr[3][3], int Rows, int Cols)
{
	short MiddleRow = Rows / 2 ; 
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d ", 2, arr[MiddleRow][j]);
		}
		cout << endl; 
	
}void PrintMiddleColOfMatrix(int arr[3][3], int Rows, int Cols)
{
	short MiddleCols  = Cols / 2 ;
		for (int i = 0; i < Rows; i++)
		{
			printf(" %0*d ", 2, arr[i][MiddleCols]);
		}
		cout << endl; 
	
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	
	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "Matrix 1\n";
	PrintMatrix(arr, 3, 3);
	cout << "\nMiddle Row of Matrix1 is:\n";
	PrintMiddleRowOfMatrix(arr,3, 3);
	cout << "\nMiddle Row of Matrix2 is:\n";
	PrintMiddleColOfMatrix(arr,3, 3);
}