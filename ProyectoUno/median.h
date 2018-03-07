#pragma once
#include <vector>

int gMedianCaseNumber;

void ParseMedianInput();

void FindMedian(std::vector<int> &leftArray, std::vector<int> &rightArray, int leftBottom, int leftTop, int rightBottom, int rightTop, int arraySize);

void PrintMedian(int leftInteger, int rightInteger);