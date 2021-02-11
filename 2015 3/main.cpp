#include <iostream>
#include<vector>
#include <fstream>



int main()
{

	int houseGrid[500][500];
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

	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			houseGrid[i][j] = 0;
		}
	}
	
	//starting house midpoint
	houseGrid[250][250] = 1;
	
	int startRowIndex = 250;
	int startColumnIndex = 250;
	for (int i = 0; i < movementInput.size(); i = i + 2)
	{
		switch (movementInput[i])
		{
		case '^':
		{
			startColumnIndex++;
			houseGrid[startRowIndex][startColumnIndex]++;
			break;
		}

		case 'v':
		{
			startColumnIndex--;
			houseGrid[startRowIndex][startColumnIndex]++;
			break;
		}

		case '>':
		{
			startRowIndex++;
			houseGrid[startRowIndex][startColumnIndex]++;
			break;
		}

		case '<':
		{
			startRowIndex--;
			houseGrid[startRowIndex][startColumnIndex]++;
			break;
		}

		default:
			break;
		}
	}

	int startRowIndexRobo = 250;
	int startColumnIndexRobo = 250;

	for (int i = 1; i < movementInput.size(); i = i + 2)
	{
		switch (movementInput[i])
		{
		case '^':
		{
			startColumnIndexRobo++;
			houseGrid[startRowIndexRobo][startColumnIndexRobo]++;
			break;
		}

		case 'v':
		{
			startColumnIndexRobo--;
			houseGrid[startRowIndexRobo][startColumnIndexRobo]++;
			break;
		}

		case '>':
		{
			startRowIndexRobo++;
			houseGrid[startRowIndexRobo][startColumnIndexRobo]++;
			break;
		}

		case '<':
		{
			startRowIndex--;
			houseGrid[startRowIndexRobo][startColumnIndexRobo]++;
			break;
		}

		default:
			break;
		}
	}

	//to keep count of houses
	int deliveryCompleteHouse=0;

	for (int i = 0; i < (500); i++)
	{
		for (int j = 0; j < (500); j++)
		{
			if (houseGrid[i][j] != 0)
			{
				deliveryCompleteHouse++;
			}
		}
	}

	for (int i = 0; i < (500); i++)
	{
		for (int j = 0; j < (500); j++)
		{
			std::cout << houseGrid[i][j];
		}
		std::cout << "\n";
	}

	std::cout << "\n\n\n\n\n\nNo of houses that recieved delivery are " << deliveryCompleteHouse<<".\n\n";
}