#include <iostream>
#include <string>
#include <fstream>
#include<vector>


//dont know how to pass the lightGridPtr to SwitchLight func. So, making it gloabal.
const int lightGridSize = 1000;
int(*lightGridPtr)[lightGridSize] = new int[lightGridSize][lightGridSize];



void SwitchLight(int i1, int j1, int i2, int j2, bool toggle, bool turnOff, bool turnOn)
{
	if (toggle)
	{
		for (int i = i1; i <= i2; i++)
		{
			for (int j = j1; j <= j2; j++)
			{
				lightGridPtr[i][j] += 2;
			}
		}
	}
	else if (turnOff)
	{
		for (int i = i1; i <= i2; i++)
		{
			for (int j = j1; j <= j2; j++)
			{
				lightGridPtr[i][j] -= 1;
				if (lightGridPtr[i][j] < 0)
				{
					lightGridPtr[i][j] = 0;
				}
			}
		}
	}
	else if (turnOn)
	{
		for (int i = i1; i <= i2; i++)
		{
			for (int j = j1; j <= j2; j++)
			{
				lightGridPtr[i][j] += 1;
			}
		}
	}
}


int main()
{


	//initialize the grid with zeroes
	for (int i = 0; i < lightGridSize; i++)
	{
		for (int j = 0; j < lightGridSize; j++)
		{
			lightGridPtr[i][j] = 0;
		}
	}

	std::ifstream inputStream;
	inputStream.open("InputInstructions.txt");
	if (!inputStream)
	{
		std::cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	std::vector<std::string> instructionsVector;

	std::string inputString = "";

	while (std::getline(inputStream,inputString))
	{
		if (inputString.size() > 0)
		{
			instructionsVector.push_back(inputString);
		}
	}


	for (int i = 0; i < instructionsVector.size(); i++)
	{
		//to store start and end indexes
		int i1 = 0, j1 = 0, i2 = 0, j2 = 0;

		bool toggle = false;
		bool turnOn = false;
		bool turnOff = false;

		//to store each word of the instruction separately
		std::vector<std::string> brokenInstruction;
		std::string word = "";

		for (auto x : instructionsVector[i])
		{
			if (x == ' ')
			{
				brokenInstruction.push_back(word);
				word = "";
			}
			else if (x == ',')
			{
				brokenInstruction.push_back(word);
				word = "";
			}
			else
			{
				word = word + x;
			}
		}
		brokenInstruction.push_back(word);

		if (brokenInstruction[0]=="toggle")
		{
			toggle = true;

			i1 = std::stoi(brokenInstruction[1]);
			j1 = std::stoi(brokenInstruction[2]);
			i2 = std::stoi(brokenInstruction[4]);
			j2 = std::stoi(brokenInstruction[5]);
		}
		else if (brokenInstruction[0] == "turn")
		{
			if (brokenInstruction[1] == "on")
			{
				turnOn = true;
			}
			else if (brokenInstruction[1] == "off")
			{
				turnOff = true;
			}
			i1 = std::stoi(brokenInstruction[2]);
			j1 = std::stoi(brokenInstruction[3]);
			i2 = std::stoi(brokenInstruction[5]);
			j2 = std::stoi(brokenInstruction[6]);
		}


		SwitchLight(i1, j1, i2, j2, toggle, turnOff, turnOn);
	}


	//now count the turned on lights
	int onLightsCounter = 0;
	for (int i = 0; i < lightGridSize; i++)
	{
		for (int j = 0; j < lightGridSize; j++)
		{
			onLightsCounter += lightGridPtr[i][j];
		}
	}

	std::cout << "\nTotal brightness is " << onLightsCounter;
}