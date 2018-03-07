/* Hecho Por:
// Christopher Jaquez Prado - A01186997
// Luis Raúl Arzola López - A01186956
*/

#include <iostream>
#include <vector>
#include <string>
#include "matrix.h"
#include "median.h"

using namespace std;

void PrintResults(vector<vector<int>> result, int multiplicationCount, string header)
{
	int matrixSize = result.size();
	cout << header << endl;

	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize - 1; col++)
		{
			cout << result[row][col] << " ";
		}
		cout << result[row][matrixSize - 1] << endl;
	}

	cout << "Scalar Multiplications: " << multiplicationCount << endl << endl;
}

void SquareMatrixSum(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, vector<vector<int>> &result)
{
	int matrixSize = matrixOne.size();

	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			result[row][col] = matrixOne[row][col] + matrixTwo[row][col];
		}
	}
}

void SquareMatrixSub(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, vector<vector<int>> &result)
{
	int matrixSize = matrixOne.size();

	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			result[row][col] = matrixOne[row][col] - matrixTwo[row][col];
		}
	}
}

void StrassenMatrix(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, int matrixSize)
{

	int multiplicationCount = 0;
	vector<vector<int>> result(matrixSize, vector<int>(matrixSize));

	throw std::invalid_argument("nos dio flojera y no lo implementamos lol");

	StrassenMatrixRec(matrixOne, matrixTwo, matrixSize, multiplicationCount, result);

	PrintResults(result, multiplicationCount, "Strassen:");
}

void StrassenMatrixRec(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, int matrixSize, int &multiplicationCount, vector<vector<int>> &result)
{

}

void TraditionalMatrix(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, int matrixSize)
{
	int multiplicationCount = 0;
	vector<vector<int>> result(matrixSize, vector<int>(matrixSize));

	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			int sum = 0;

			for (int k = 0; k < matrixSize; k++)
			{
				sum += matrixOne[row][k] * matrixTwo[k][col];
				multiplicationCount++;
			}

			result[row][col] = sum;
		}
	}

	PrintResults(result, multiplicationCount, "Traditional:");
}

void ParseMatrixInput()
{
	int matrixSize;
	cin >> matrixSize;
	vector<vector<int>> matrixOne(matrixSize, vector<int>(matrixSize));
	vector<vector<int>> matrixTwo(matrixSize, vector<int>(matrixSize));
	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			cin >> matrixOne[row][col];
		}
	}
	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			cin >> matrixTwo[row][col];
		}
	}

	TraditionalMatrix(matrixOne, matrixTwo, matrixSize);
	StrassenMatrix(matrixOne, matrixTwo, matrixSize);
}

int main()
{
	while (true)
	{
		ParseMedianInput();
	}
}

bool ParseMedianInput() {
	/*
	2
	5
	1
	4
	7
	8
	10
	2
	9
	11
	14
	15
	*/

	int arraySize;

	cin >> arraySize;

	if (arraySize <= 0) return false;

	vector<int> leftArray(arraySize), rightArray(arraySize);

	for (int i = 0; i < arraySize; i++) {
		cin >> leftArray[i];
	}

	for (int i = 0; i < arraySize; i++) {
		cin >> rightArray[i];
	}

	FindMedian(leftArray, rightArray, 0, arraySize, 0, arraySize);
	return true;
}

void FindMedian(vector<int> leftArray, vector<int> rightArray, int leftBottom, int leftTop, int rightBottom, int rightTop) {
	
}