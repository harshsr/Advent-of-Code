#include"BoxPaper.h"
#include<iostream>

int main()
{
	std::vector<BoxPaper> paperList;

	std::cout<<("\nInput dimensions data one by one. Input 0 to stop\n");

	std::string inpstring = "0";

	int totalArea = 0;
	int totalRibbonLength = 0;

	int i = 0;

	while (std::cin >> inpstring && inpstring != "0")
	{
		paperList.push_back(BoxPaper(inpstring));

		totalArea = totalArea + paperList[i].AreaCalculation();
		totalRibbonLength = totalRibbonLength + paperList[i].RibbonLengthCalculator();
		i++;
	}

	std::cout << "\n\nTotal area :\t" << totalArea<<".\nRibbon length:\t"<<totalRibbonLength<<".\n";

	/*
	std::string s;
	std::cin >> s;
	BoxPaper paper1 = { s };

	double area = paper1.AreaCalculation();
	std::cout << "\narea\t" + std::to_string(area);
	*/
	
}