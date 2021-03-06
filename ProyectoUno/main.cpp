/* Hecho Por:
// Christopher Jaquez Prado - A01186997
// Luis Ra�l Arzola L�pez - A01186956
*/

#include <iostream>
#include <vector>
#include <string>
#include "matrix.h"
#include "median.h"

using namespace std;

int main()
{
	int optionChosen;
	bool continueLoop = true;

	cout << "Welcome to Chris\' and Luis\' Project 1 Solver." << endl;
	cout << "Christopher Jaquez Prado -- A01186997" << endl << "Luis Raul Arzola Lopez -- A01186956" << endl;
	cout << "==========================================================================" << endl << endl;

	while (continueLoop)
	{
		cout << "Please choose an option from the menu:" << endl;
		cout << "(1) Find Median of 2 Arrays of Length n" << endl;
		cout << "(2) Multiply a Matrix Using Both Traditional and Strassen Methods" << endl;
		cout << "(0) Exit." << endl;

		cin >> optionChosen;

		cout << endl;

		switch (optionChosen) {
			case 0:
				cout << endl << "Thank you!";
				continueLoop = false;
				break;
			case 1: 
				cout << "Beginning Median Algorithm." << endl << "Please input the number of cases followed by the cases." << endl << endl;
				ParseMedianInput();
				break;
			case 2:
				cout << "Beginning Matrix Multiplication." << endl << "Input a 0 as Matrix Size to return to the previous menu." << endl << endl;
				while(ParseMatrixInput());
				break;
			default:
				cout << "Invalid option!";

		}
	}
}

void PrintMatrixResults(vector<vector<int>> result, int multiplicationCount, string header)
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

void Strassen2X2(vector<vector<int>> matrixA, vector<vector<int>> matrixB, vector<vector<int>> &result, int &multiplicationCount)
{
	int a = matrixA[0][0];
	int b = matrixA[0][1];
	int c = matrixA[1][0];
	int d = matrixA[1][1];
	int e = matrixB[0][0];
	int f = matrixB[0][1];
	int g = matrixB[1][0];
	int h = matrixB[1][1];

	int p1 = a * (f - h);
	int p2 = (a + b) * h;
	int p3 = (c + d) * e;
	int p4 = d * (g - e);
	int p5 = (a + d) * (e + h);
	int p6 = (b - d) * (g + h);
	int p7 = (a - c) * (e + f);
	multiplicationCount += 7;

	result[0][0] = p5 + p4 - p2 + p6;
	result[0][1] = p1 + p2;
	result[1][0] = p3 + p4;
	result[1][1] = p1 + p5 - p3 - p7;
}

void SquareMatrixSum(int matrixSize, vector<vector<int>> matrixA, vector<vector<int>> matrixB, vector<vector<int>> &result)
{
	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			result[row][col] = matrixA[row][col] + matrixB[row][col];
		}
	}
}

void SquareMatrixSub(int matrixSize, vector<vector<int>> matrixA, vector<vector<int>> matrixB, vector<vector<int>> &result)
{
	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			result[row][col] = matrixA[row][col] - matrixB[row][col];
		}
	}
}

void StrassenMatrixRebuildMatrix(vector<vector<int>> &toRebuild, int submatrixSize,
	vector<vector<int>> a11, vector<vector<int>> a12, vector<vector<int>> a21, vector<vector<int>> a22)
{
	for (int row = 0; row < submatrixSize; row++)
	{
		for (int col = 0; col < submatrixSize; col++)
		{
			toRebuild[row][col] = a11[row][col];
			toRebuild[row][col + submatrixSize] = a12[row][col];
			toRebuild[row + submatrixSize][col] = a21[row][col];
			toRebuild[row + submatrixSize][col + submatrixSize] = a22[row][col];
		}
	}
}

void StrassenSubdivideBothMatrices(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, int newSize,
	vector<vector<int>> &a11, vector<vector<int>> &a12, vector<vector<int>> &a21, vector<vector<int>> &a22,
	vector<vector<int>> &b11, vector<vector<int>> &b12, vector<vector<int>> &b21, vector<vector<int>> &b22)
{
	for (int row = 0; row < newSize; row++)
	{
		for (int col = 0; col < newSize; col++)
		{
			a11[row][col] = matrixOne[row][col];
			a12[row][col] = matrixOne[row][col + newSize];
			a21[row][col] = matrixOne[row + newSize][col];
			a22[row][col] = matrixOne[row + newSize][col + newSize];

			b11[row][col] = matrixTwo[row][col];
			b12[row][col] = matrixTwo[row][col + newSize];
			b21[row][col] = matrixTwo[row + newSize][col];
			b22[row][col] = matrixTwo[row + newSize][col + newSize];
		}
	}
}

void StrassenMatrixRec(vector<vector<int>> matrixA, vector<vector<int>> matrixB,
	int matrixSize, int &multiplicationCount, vector<vector<int>> &result)
{
	if (matrixSize == 2)
	{
		Strassen2X2(matrixA, matrixB, result, multiplicationCount);
		return;
	}

	// Create sub-matrices
	int subMatrixSize = matrixSize / 2;
	vector<vector<int>>	a11(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> a12(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> a21(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> a22(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> b11(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> b12(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> b21(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> b22(subMatrixSize, vector<int>(subMatrixSize));

	StrassenSubdivideBothMatrices(matrixA, matrixB, subMatrixSize,
		a11, a12, a21, a22,
		b11, b12, b21, b22);

	// Start M1-M7 operations
	// All the sum and sub operations SET the value, instead of adding, so helper matrices can be reused for readability.
	vector<vector<int>> reusableMatrixA(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> reusableMatrixB(subMatrixSize, vector<int>(subMatrixSize));

	// M1 || (a11 + a22) * (b11 + b22)
	vector<vector<int>> p1(subMatrixSize, vector<int>(subMatrixSize));
	SquareMatrixSum(subMatrixSize, a11, a22, reusableMatrixA);
	SquareMatrixSum(subMatrixSize, b11, b22, reusableMatrixB);
	StrassenMatrixRec(reusableMatrixA, reusableMatrixB, subMatrixSize, multiplicationCount, p1);

	// M2 || (a21 + a22) * (b11)
	vector<vector<int>> p2(subMatrixSize, vector<int>(subMatrixSize));
	SquareMatrixSum(subMatrixSize, a21, a22, reusableMatrixA);
	StrassenMatrixRec(reusableMatrixA, b11, subMatrixSize, multiplicationCount, p2);

	// M3 || (a11) * (b12 - b22)
	vector<vector<int>> p3(subMatrixSize, vector<int>(subMatrixSize));
	SquareMatrixSub(subMatrixSize, b12, b22, reusableMatrixB);
	StrassenMatrixRec(a11, reusableMatrixB, subMatrixSize, multiplicationCount, p3);

	// M4 || (a22) * (b21 - b11)
	vector<vector<int>> p4(subMatrixSize, vector<int>(subMatrixSize));
	SquareMatrixSub(subMatrixSize, b21, b11, reusableMatrixB);
	StrassenMatrixRec(a22, reusableMatrixB, subMatrixSize, multiplicationCount, p4);

	// M5 || (a11 + a12) * (b22)  
	vector<vector<int>> p5(subMatrixSize, vector<int>(subMatrixSize));
	SquareMatrixSum(subMatrixSize, a11, a12, reusableMatrixA);
	StrassenMatrixRec(reusableMatrixA, b22, subMatrixSize, multiplicationCount, p5);

	// M6 || (a21 - a11) * (b11 + b12)
	vector<vector<int>> p6(subMatrixSize, vector<int>(subMatrixSize));
	SquareMatrixSub(subMatrixSize, a21, a11, reusableMatrixA);
	SquareMatrixSum(subMatrixSize, b11, b12, reusableMatrixB);
	StrassenMatrixRec(reusableMatrixA, reusableMatrixB, subMatrixSize, multiplicationCount, p6);

	// M7 || (a12 - a22) * (b21 + b22)
	vector<vector<int>> p7(subMatrixSize, vector<int>(subMatrixSize));
	SquareMatrixSub(subMatrixSize, a12, a22, reusableMatrixA);
	SquareMatrixSum(subMatrixSize, b21, b22, reusableMatrixB);
	StrassenMatrixRec(reusableMatrixA, reusableMatrixB, subMatrixSize, multiplicationCount, p7);

	// Calculate Result
	vector<vector<int>> res11(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> res12(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> res21(subMatrixSize, vector<int>(subMatrixSize));
	vector<vector<int>> res22(subMatrixSize, vector<int>(subMatrixSize));

	// R11 || M1 + M4 - M5 + M7
	SquareMatrixSum(subMatrixSize, p1, p4, reusableMatrixA);
	SquareMatrixSum(subMatrixSize, reusableMatrixA, p7, reusableMatrixB);
	SquareMatrixSub(subMatrixSize, reusableMatrixB, p5, res11);

	// R12 || M3 + M5
	SquareMatrixSum(subMatrixSize, p3, p5, res12);

	// R21 || M2 + M4
	SquareMatrixSum(subMatrixSize, p2, p4, res21);

	// R22 || M1 + M3 - M2 + M6
	SquareMatrixSum(subMatrixSize, p1, p3, reusableMatrixA);
	SquareMatrixSum(subMatrixSize, reusableMatrixA, p6, reusableMatrixB);
	SquareMatrixSub(subMatrixSize, reusableMatrixB, p2, res22);

	StrassenMatrixRebuildMatrix(result, subMatrixSize, res11, res12, res21, res22);
}

void StrassenMatrix(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, int matrixSize)
{
	int multiplicationCount = 0;

	vector<vector<int>> result(matrixSize, vector<int>(matrixSize));

	StrassenMatrixRec(matrixOne, matrixTwo, matrixSize, multiplicationCount, result);

	PrintMatrixResults(result, multiplicationCount, "Strassen:");
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

	PrintMatrixResults(result, multiplicationCount, "Traditional:");
}

bool ParseMatrixInput()
{
	int matrixSize;
	cin >> matrixSize;
	if (matrixSize <= 0) return false;
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
	return true;
}

void ParseMedianInput() {

	int numberOfCases;

	cin >> numberOfCases; 

	for (gMedianCaseNumber = 1; gMedianCaseNumber <= numberOfCases; gMedianCaseNumber++) {
		int arraySize;

		cin >> arraySize;

		vector<int> leftArray(arraySize), rightArray(arraySize);

		for (int i = 0; i < arraySize; i++) {
			cin >> leftArray[i];
		}

		for (int i = 0; i < arraySize; i++) {
			cin >> rightArray[i];
		}

		FindMedian(leftArray, rightArray, 0, arraySize-1, 0, arraySize-1, arraySize);
	}
}

void FindMedian(vector<int> &leftArray, vector<int> &rightArray, int leftBottom, int leftTop, int rightBottom, int rightTop, int arraySize) {
	int currentSize = leftTop - leftBottom + 1,
		leftMidIndex = ceil((float)(leftBottom + leftTop) / 2.0f),
		rightMidIndex = (rightBottom + rightTop) >> 1,
		leftMid = leftArray[leftMidIndex],
		rightMid = rightArray[rightMidIndex];

	if (currentSize == 1 || ((rightMidIndex <= 0 || leftMid > rightArray[rightMidIndex - 1]) && (rightMidIndex >= arraySize - 1 || leftMid < rightArray[rightMidIndex + 1]))) {
		PrintMedian(leftMid, rightMid);	
	} else if (rightMidIndex <= 0 || leftMid > rightArray[rightMidIndex - 1]) {
		FindMedian(leftArray, rightArray, leftBottom, leftMidIndex-1, rightMidIndex+1, rightTop, arraySize);
	} else {
		FindMedian(leftArray, rightArray, leftMidIndex+1, leftTop, rightBottom, rightMidIndex-1, arraySize);
	}
}

void PrintMedian(int leftInteger, int rightInteger) {
	cout << "Median case " << gMedianCaseNumber << ": " << ((float)(leftInteger + rightInteger) / 2.0f) << endl << endl;
}