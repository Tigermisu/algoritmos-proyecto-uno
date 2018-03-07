#pragma once
#include <vector>
#include <string>

using namespace std;
void PrintMatrixResults(vector<vector<int>> result, int multiplicationCount, string header);

void Strassen2X2(vector<vector<int>> matrixA, vector<vector<int>> matrixB, vector<vector<int>> &result, int &multiplicationCount);

void SquareMatrixSum(int matrixSize, vector<vector<int>> matrixA, vector<vector<int>> matrixB, vector<vector<int>> &result);

void SquareMatrixSub(int matrixSize, vector<vector<int>> matrixA, vector<vector<int>> matrixB, vector<vector<int>> &result);

void StrassenMatrixRebuildMatrix(vector<vector<int>> &toRebuild, int submatrixSize,
	vector<vector<int>> a11, vector<vector<int>> a12, vector<vector<int>> a21, vector<vector<int>> a22);

void StrassenSubdivideBothMatrices(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, int newSize,
	vector<vector<int>> &a11, vector<vector<int>> &a12, vector<vector<int>> &a21, vector<vector<int>> &a22,
	vector<vector<int>> &b11, vector<vector<int>> &b12, vector<vector<int>> &b21, vector<vector<int>> &b22);

void StrassenMatrixRec(vector<vector<int>> matrixA, vector<vector<int>> matrixB, int matrixSize, int &multiplicationCount, vector<vector<int>> &result);

void StrassenMatrix(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, int matrixSize);

void TraditionalMatrix(vector<vector<int>> matrixOne, vector<vector<int>> matrixTwo, int matrixSize);

bool ParseMatrixInput();