/* 
* 
* Question 
* 
* 
Today, the Elves are playing a game called look-and-say. They take turns making sequences by reading aloud the previous sequence and using that reading as the next sequence. For example, 211 is read as "one two, two ones", which becomes 1221 (1 2, 2 1s).

Look-and-say sequences are generated iteratively, using the previous value as input for the next step. For each step, take the previous value, and replace each run of digits (like 111) with the number of digits (3) followed by the digit itself (1).

For example:

1 becomes 11 (1 copy of digit 1).
11 becomes 21 (2 copies of digit 1).
21 becomes 1211 (one 2 followed by one 1).
1211 becomes 111221 (one 1, one 2, and two 1s).
111221 becomes 312211 (three 1s, two 2s, and one 1).
Starting with the digits in your puzzle input, apply this process 40 times. What is the length of the result?

Your puzzle input is 1321131112.
*/

#include<iostream>
#include <vector>
#include "Source.h"


void GetInput(int& InputNumber, int& NumberOfIterations)
{

	std::cout << "Enter input number\n>> ";
	std::cin >> InputNumber;
	if (!std::cin.good())
	{
		std::cout << "Invalid Input";
	}
	std::cout << "Enter Number of iterations to perform\n>> ";
	std::cin >> NumberOfIterations;
	if (!std::cin.good())
	{
		std::cout << "Invalid Input";
	}
}

void SplitIntIntoIntVector(int& InputNumber, std::vector<int>& InputNumberSplitUp)
{
	while (!(InputNumber == 0))
	{
		InputNumberSplitUp.push_back((InputNumber) % 10);
		InputNumber = InputNumber / 10;
	}
	std::reverse(InputNumberSplitUp.begin(), InputNumberSplitUp.end());
}

void PerformLookAndSay(const int NumberOfIterationsDesired,std::vector<int>& InputNumberSplit, std::vector<int>& NewNumber)
{
	std::vector<int> LocalVec = InputNumberSplit;
	int j = 1;
	for (int p = 0; p < NumberOfIterationsDesired; p++)
	{
		for (int i = 0; i < LocalVec.size(); i++)
		{
			if (i == LocalVec.size() - 1)
			{
				NewNumber.push_back(j);
				NewNumber.push_back(LocalVec[i]);
			}
			else
			{
				if (LocalVec[i] == LocalVec[i + 1])
				{
					j++;
				}
				else
				{
					NewNumber.push_back(j);
					NewNumber.push_back(LocalVec[i]);
					j = 1;
				}
			}

		}

		LocalVec = NewNumber;
		NewNumber.clear();
	}
	NewNumber = LocalVec;
}

int main()
{
	int InputNumber;
	std::vector<int> InputNumberSplitUp;
	std::vector<int> NewNumber;
	int NumberOfIteration = 0;

	GetInput(InputNumber,NumberOfIteration);

	SplitIntIntoIntVector(InputNumber, InputNumberSplitUp);

	PerformLookAndSay(NumberOfIteration, InputNumberSplitUp, NewNumber);
	
	std::cout << "\n" << NewNumber.size();
}