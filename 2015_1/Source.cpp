#include<iostream>
#include<string>
#include <string.h>
#include<vector>
int main()
{
	std::vector<char> instructions;
	char inputChar;
	std::cout << "\nWrite instructions for Santa.\n";
	while (std::cin >> inputChar && inputChar != '0')
	{
		instructions.push_back(inputChar);
	}

	int floorNumber = 0;

	std::vector<int> firstBasementFloorPosition = { 0 };

	for (int i = 0; i < instructions.size(); i++)
	{
		if (instructions[i] == '(')
		{
			floorNumber++;
		}
		else if (instructions[i] == ')')
		{
			floorNumber--;
			if (floorNumber == (-1))
			{
				firstBasementFloorPosition.push_back(i + 1);
			}
		}
		else
		{
			std::cout << "\nInvalid instructions.\n";
			abort();
		}
	}

	std::cout << "\nSanta will go to floor number " << floorNumber << ".\nFirst time enters the basement at "<<firstBasementFloorPosition[1]<<".\n";
}