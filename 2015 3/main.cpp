#include <iostream>
#include<vector>
#include <fstream>



int main()
{
	const int gridMaxIndex = 2100;
	int (*houseGridPtr)[gridMaxIndex] = new int[gridMaxIndex][gridMaxIndex];

	std::vector<char> movementInput;

	std::ifstream inFile;
	char c;

	inFile.open("Input.txt");
	if (!inFile) {
		std::cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}
	
	while (inFile >> c)
	{
		movementInput.push_back(c);
	}

	inFile.close();

	//initializing the house grid with zeros

	for (int i = 0; i < gridMaxIndex; i++)
	{
		for (int j = 0; j < gridMaxIndex; j++)
		{
			houseGridPtr[i][j] = 0;
		}
	}
	
	//starting house midpoint
	houseGridPtr[gridMaxIndex/2][gridMaxIndex/2] = 1;
	
	int startRowIndex = gridMaxIndex/2;
	int startColumnIndex = gridMaxIndex/2;
	for (int i = 0; i < movementInput.size(); i = i + 2)
	{
		switch (movementInput[i])
		{
		case '^':
		{
			startColumnIndex++;
			houseGridPtr[startRowIndex][startColumnIndex]++;
			break;
		}

		case 'v':
		{
			startColumnIndex--;
			houseGridPtr[startRowIndex][startColumnIndex]++;
			break;
		}

		case '>':
		{
			startRowIndex++;
			houseGridPtr[startRowIndex][startColumnIndex]++;
			break;
		}

		case '<':
		{
			startRowIndex--;
			houseGridPtr[startRowIndex][startColumnIndex]++;
			break;
		}

		default:
			break;
		}
	}

	int startRowIndexRobo = gridMaxIndex/2;
	int startColumnIndexRobo = gridMaxIndex/2;

	for (int i = 1; i < movementInput.size(); i = i + 2)
	{
		switch (movementInput[i])
		{
		case '^':
		{
			startColumnIndexRobo++;
			houseGridPtr[startRowIndexRobo][startColumnIndexRobo]++;
			break;
		}

		case 'v':
		{
			startColumnIndexRobo--;
			houseGridPtr[startRowIndexRobo][startColumnIndexRobo]++;
			break;
		}

		case '>':
		{
			startRowIndexRobo++;
			houseGridPtr[startRowIndexRobo][startColumnIndexRobo]++;
			break;
		}

		case '<':
		{
			startRowIndex--;
			houseGridPtr[startRowIndexRobo][startColumnIndexRobo]++;
			break;
		}

		default:
			break;
		}
	}

	//to keep count of houses
	int deliveryCompleteHouse=0;

	for (int i = 0; i < (gridMaxIndex); i++)
	{
		for (int j = 0; j < (gridMaxIndex); j++)
		{
			if (houseGridPtr[i][j] != 0)
			{
				deliveryCompleteHouse++;
			}
		}
	}

	for (int i = 0; i < (gridMaxIndex); i++)
	{
		for (int j = 0; j < (gridMaxIndex); j++)
		{
			std::cout << houseGridPtr[i][j];
		}
		std::cout << "\n";
	}

	std::cout << "\n\n\n\n\n\nNo of houses that recieved delivery are " << deliveryCompleteHouse<<".\n\n";
}