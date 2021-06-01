#pragma once

void GetInput(int& InputNumber);

void SplitIntIntoIntVector(int& InputNumber, std::vector<int>& InputNumberSplitUp);

void PerformLookAndSay(int NumberOfIterationsDesired, std::vector<int>& InputNumberSplitUp, std::vector<int>& NewNumber);
