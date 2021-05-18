// This program is a solution to advent of code 2015 day 8
// Part 1 is done. This code is for part 2


#include<iostream>
#include <vector>
#include<string>
#include <fstream>


int NumEncodedChars(const std::string& InString)
{
	int TotalCharsLocal = 0;

	for (int i = 0; i < (InString.length()); i++)
	{

		if (InString.at(i) == '\"' || InString.at(i) == '\\')
		{
			
			TotalCharsLocal = TotalCharsLocal + 2;
		}
		else
		{
			TotalCharsLocal = TotalCharsLocal + 1;
		}

	}



	return TotalCharsLocal+2;
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

	int TotalEncodedChars = 0;
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
		TotalEncodedChars = TotalEncodedChars + NumEncodedChars(InputStrings[i]);
		TotalCodeChars = TotalCodeChars + NumCodeChars(InputStrings[i]);
	}



	std::cout <<TotalEncodedChars - TotalCodeChars;

}

