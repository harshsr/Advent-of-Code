#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>


int main()
{


	std::vector<std::string> instructionsVector;

	std::ifstream inputStream;
	inputStream.open("Input.txt");
	if (!inputStream)
	{
		std::cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	std::string inputString = "";

	while (std::getline(inputStream, inputString))
	{
		if (inputString.size() > 0)
		{
			instructionsVector.push_back(inputString);
		}
	}

	//all the output wire names stored in following vector 
	std::vector<std::string> allWireNamesSorted;

	for (int i = 0; i < instructionsVector.size(); i++)
	{

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
			else
			{
				word = word + x;
			}
		}
		brokenInstruction.push_back(word);

		allWireNamesSorted.push_back(brokenInstruction.back());
	}
	
	for (int i = 0; i < allWireNamesSorted.size(); i++)
	{
		std::cout << "\n " << allWireNamesSorted[i];
	}
}
