// This program is a solution to advent of code 2015 day 8


#include<iostream>
#include <vector>
#include<string>
#include <fstream>


int NumMemoryChars(const std::string& InString)
{
	int TotalCharsLocal = 0;

	//start this for loop with index 1 because our strings contain the initial and final double quotation marks
	//End loop at length - 1 because our strings contain the initial and final double quotation marks
	for (int i = 1; i < (InString.length() - 1); i++)
	{
		if (InString.at(i) == ' ')
		{
			TotalCharsLocal = TotalCharsLocal;
		}

		if (InString.at(i) == '\\')
		{
			if (InString.at(i + 1) == '\\' || InString.at(i + 1) == '\"')
			{
				TotalCharsLocal = TotalCharsLocal + 1;
				i = i + 1;
			}
			else if (InString.at(i + 1) == 'x')
			{
				TotalCharsLocal = TotalCharsLocal + 1;
				i = i + 3;
			}
		}
		else
		{
			TotalCharsLocal = TotalCharsLocal + 1;
		}

	}



	return TotalCharsLocal;
}

int NumCodeChars(const std::string& InString)
{
	int TotalCharsLocal = 0;
	for (int i = 0; i < InString.length(); i++)
	{
		TotalCharsLocal = TotalCharsLocal + 1;
	}

	return TotalCharsLocal;
}


int main()
{

	int TotalMemoryChars = 0;
	int TotalCodeChars = 0;
	std::vector<std::string> InputStrings;


	std::ifstream InputStream;
	InputStream.open("InputInstructions.txt");
	if (!InputStream)
	{
		std::cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	std::string InputString = "";


	while (std::getline(InputStream, InputString))
	{
		if (InputString.size() > 0)
		{
			InputStrings.push_back(InputString);
		}
	}

	for(int i = 0;i<InputStrings.size();i++)
	{
		TotalMemoryChars = TotalMemoryChars + NumMemoryChars(InputStrings[i]);
		TotalCodeChars = TotalCodeChars + NumCodeChars(InputStrings[i]);
	}



	std::cout << TotalCodeChars - TotalMemoryChars;

}

