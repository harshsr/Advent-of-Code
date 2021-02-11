

//first part solution deleted. This is second part

#include <iostream>
#include<string>
#include<fstream>

using namespace std;

bool OneLetterBetweenReq(string s)
{
	char c = '0';
	for (int i = 0; i < (s.size() - 2); i++)    // size - 2 to stop accessing of out of range stuff
	{
		if (s[i] == s[i + 2])
		{
			return true;
		}
	}

	return false;
}

bool DoubleRepetitionReq(string s)
{
	string substr = "00";
	string substr2 = "00";
	for (int i = 0; i < (s.size() - 3); i++)   //size - 3 because we don't want to access out of range stuff
	{
		substr = s.substr(i, 2);
		for (int j = i + 2; j < (s.size() - 1); j++)   //size - 1 because we don't want to access out of range stuff
		{
			substr2 = s.substr(j, 2);
			if (substr == substr2)
				return true;
		}
	}

	return false;
}

bool StringChecker(string s)
{
	if (DoubleRepetitionReq(s)&&OneLetterBetweenReq(s))
	{
		return true;
	}

	return false;
}

int main()
{
	std::ifstream inFile;
	char c;

	inFile.open("list.txt");
	if (!inFile) {
		std::cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	string s;
	//cin >> s;
	int numberOfNiceStrings = 0;
	int totalStrings = 0;

	while (getline(inFile, s))
	{
		if (StringChecker(s))
		{
			numberOfNiceStrings++;
		}
		totalStrings++;
	}


	/*if (StringChecker(s))
	{
		numberOfNiceStrings++;
	}
	totalStrings++;*/

	cout << "Number of nice strings is: " << numberOfNiceStrings << "\n"<<"Total strings:"<<totalStrings<<"\n";
}