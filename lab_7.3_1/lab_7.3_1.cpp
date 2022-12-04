// lab_7.3_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** y, const int colcount, const int rowcount, const int Low, const int High)
{
	for (int i = 0; i < rowcount; i++)
		for (int j = 0; j < colcount; j++)
			y[i][j] = Low + rand() % (High - Low + 1);
}


void Print(int** y, const int colcount, const int rowcount)
{
	cout << endl;
	for (int i = 0; i < rowcount; i++)
	{
		for (int j = 0; j < colcount; j++)
			cout << setw(4) << y[i][j];
		cout << endl;
	}
	cout << endl;
}

int Nulls(int** arr, const int colcount, const int rowcount)
{
	int k = 0;
	for (int j = 0; j < colcount; j++)
	{
		for (int i = 0; i < rowcount; i++)
		{
			if (arr[i][j] == 0)
			{
				k++;
				break;
			}
		}
	}

	return k;
}
void Long(int** b, const int colcount, const int rowcount)
{
	int maxRow = 0;
	int prevElement = 0;
	int maxSequence = 0;

	for (int i = 0; i < rowcount; i++)
	{
		prevElement = b[i][0];
		int itr = 0;
		int maxSequenceInRow = 1;
		for (int j = 1; j < colcount; j++)
		{
			if (prevElement == b[i][j])
			{
				itr++;
				if (maxSequenceInRow < itr)
				{
					maxSequenceInRow = itr;
				}
			}
			else
			{
				itr = 0;
				prevElement = b[i][j];
			}
		}

		if (maxSequenceInRow > maxSequence)
		{
			maxSequence = itr;
			maxRow = i;
		}
	}

	cout << "Row with max sequence - " << maxRow + 1;
}


int main()
{
	srand((unsigned)time(NULL));
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	int Low = 0;
	int High = 5;

	Create(a, colCount, rowCount, Low, High);
	Print(a, colCount, rowCount);

	int d = Nulls(a, colCount, rowCount);
	cout << d;

	Long(a, colCount, rowCount);

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
