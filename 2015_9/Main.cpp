/*

Question :

Every year, Santa manages to deliver all of his presents in a single night.

This year, however, he has some new locations to visit; his elves have provided him the distances between every pair of locations. He can start and end at any two (different) locations he wants, but he must visit each location exactly once. What is the shortest distance he can travel to achieve this?

For example, given the following distances:

London to Dublin = 464
London to Belfast = 518
Dublin to Belfast = 141
The possible routes are therefore:

Dublin -> London -> Belfast = 982
London -> Dublin -> Belfast = 605
London -> Belfast -> Dublin = 659
Dublin -> Belfast -> London = 659
Belfast -> Dublin -> London = 605
Belfast -> London -> Dublin = 982
The shortest of these is London -> Dublin -> Belfast = 605, and so the answer is 605 in this example.

What is the distance of the shortest route?


Part 2 - Longest Distance
*/

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>


struct TwoDestination
{
    std::string LocationOne;
    std::string LocationTwo;
    float Distance;

    TwoDestination()
    {
        LocationOne = "";
        LocationTwo = "";
        Distance = 0.0f;
    }
    TwoDestination(std::string Location1, std::string Location2, float InDistance)
    {
        LocationOne = Location1;
        LocationTwo = Location2;
        Distance = InDistance;
    }

};

std::vector<TwoDestination> TwoDestinationsVector; // Global variable bad practice. I know.

int CalculateTotalRouteDistance(std::vector<std::string> RouteVector)
{
    int RouteDistance = 0;
    for (int i = 0; i < RouteVector.size()-1; i++)
    {
        for (int j = 0; j < TwoDestinationsVector.size(); j++)
        {
            if (TwoDestinationsVector[j].LocationOne == RouteVector[i] && TwoDestinationsVector[j].LocationTwo == RouteVector[i + 1])
            {
                RouteDistance = RouteDistance + TwoDestinationsVector[j].Distance;
            }
            else if (TwoDestinationsVector[j].LocationTwo == RouteVector[i] && TwoDestinationsVector[j].LocationOne == RouteVector[i + 1])
            {
                RouteDistance = RouteDistance + TwoDestinationsVector[j].Distance;
            }
        }
    }

    return RouteDistance;
}

void permute(std::string a, int l, int r)
{
    // Base case
    if (l == r)
    {

    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            std::swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r);

            //backtrack
            std::swap(a[l], a[i]);
        }
    }
}


int main()
{
    std::vector<std::string> InputStrings;
    std::vector<std::string> Locations;
    int TotalMinimumDistance = 316;   // We want a min so this variable is initialized to the default Locations vector route distance
    std::vector<std::string> CurrentShortestRoute = Locations;
    std::vector<std::string> CurrentLongestRoute = Locations;
    int TotalMaximumDistance = 316;


    // store input line by line
    std::ifstream InputStream;
    InputStream.open("Input.txt");
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


    // Break up input to store a vector of TwoDestination struct and a vector of all the unique locations
    for (int i = 0; i < InputStrings.size(); i++)
    {
        TwoDestination CurrentTwoDestinations;
        int LocationStructIndex = 0;
        int WordStartIndex = 0; // we access and modify this index whenever we get a whitespace to store that substring into a seperate location. 
        for (int j = 0; j < InputStrings[i].size(); j++)
        {
            if (InputStrings[i].at(j) == ' ')
            {
                if (InputStrings[i].substr(WordStartIndex, j - WordStartIndex) == "to")
                {

                }
                else if (InputStrings[i].substr(WordStartIndex, j - WordStartIndex) == "=")
                {

                }
                else
                {
                    if (LocationStructIndex == 0)
                    {
                        CurrentTwoDestinations.LocationOne = InputStrings[i].substr(WordStartIndex, j - WordStartIndex);
                        LocationStructIndex++;

                        if (std::find(Locations.begin(), Locations.end(), InputStrings[i].substr(WordStartIndex, j - WordStartIndex)) != Locations.end()) {

                        }
                        else {
                            Locations.push_back(InputStrings[i].substr(WordStartIndex, j - WordStartIndex));
                        }
                    }
                    else if (LocationStructIndex == 1)
                    {
                        CurrentTwoDestinations.LocationTwo = InputStrings[i].substr(WordStartIndex, j - WordStartIndex);

                        if (std::find(Locations.begin(), Locations.end(), InputStrings[i].substr(WordStartIndex, j - WordStartIndex)) != Locations.end()) {

                        }
                        else {
                            Locations.push_back(InputStrings[i].substr(WordStartIndex, j - WordStartIndex));
                        }
                    }
                }
                WordStartIndex = j + 1;
            }
        }
        CurrentTwoDestinations.Distance = std::stoi(InputStrings[i].substr(WordStartIndex, InputStrings[i].size() - WordStartIndex + 2));

        TwoDestinationsVector.push_back(CurrentTwoDestinations);
    }



    // Create permutations of the location vector and check if distance is lowered.

    while (std::next_permutation(Locations.begin(), Locations.end()))
    {
        int CurrentRouteDistance = CalculateTotalRouteDistance(Locations);
        if (CurrentRouteDistance < TotalMinimumDistance)
        {
            TotalMinimumDistance = CurrentRouteDistance;
            CurrentShortestRoute = Locations;
        }
        if (CurrentRouteDistance > TotalMaximumDistance)
        {
            TotalMaximumDistance = CurrentRouteDistance;
            CurrentLongestRoute = Locations;
        }
    }

    for (int i = 0; i < Locations.size(); i++)
    {
        std::cout << CurrentLongestRoute[i] << "\n";
    }
    std::cout << TotalMaximumDistance;
}