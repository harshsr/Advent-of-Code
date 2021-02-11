#include <iostream>
#include<string>

using namespace std;

struct Vowels
{
	char a, e, i, o, u;
}vowels;
//setting vowels
vowels.a = 'a';
vowels.e = 'e';
vowels.i = 'i';
vowels.o = 'o';
vowels.u = 'u';

struct NaughtySubstrings {
	string ab, cd, pq, xy;
}naughtySubstrings;
//setting naughty substrings
naughtySubstrings.ab = "ab";
naughtySubstrings.cd = "cd";
naughtySubstrings.pq = "pq";
naughtySubstrings.xy = "xy";



bool VowelReq(string s)
{

}

bool LetterRepetitionReq(string s)
{

}

bool NaughtySubstrReq(string s)
{

}


bool StringChecker(string s)
{
	if (VowelReq(s) && LetterRepetitionReq(s) && NaughtySubstrReq(s))
	{
		return true;
	}

	return false;
}

int main()
{



	ifstream inputList;
	inputList.open("list.txt");
	if (!inputList)
	{
		std::cerr << "Unable to open file datafile.txt";
		exit(1);
	}

	string s;
	int numberOfNiceStrings = 0;
	while (getline(inputList, s))
	{
		if (StringChecker(s))
		{
			numberOfNiceStrings++;
		}
	}

	cout << "Number of nice strings is: " << numberOfNiceStrings << "\n";
}