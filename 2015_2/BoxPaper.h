#pragma once
#include <string>
#include<algorithm>
#include<vector>

class BoxPaper
{
private:
	int length;
	int width;
	int height;

public:
	BoxPaper(std::string inputstr)
	{
		std::string lengthstr, widthstr, heightstr;
		int p = 0;
		for (int i = 0; i < inputstr.length(); i++)
		{
			if (inputstr.at(i) == 'x')
			{
				switch (p)
				{

				case(0):
				{
					if (i == 2)
					{
						lengthstr = std::string(1, inputstr[i - 2]) + std::string(1, inputstr[i - 1]);
					}
					else if (i == 1)
					{
						lengthstr = std::string(1, inputstr[i - 1]);
					}
					p++;
					break;
				}
				case(1):
				{
					if (lengthstr.length() == 1)
					{
						if (i == 3)
						{
							widthstr = std::string(1, inputstr[i - 1]);
						}
						else if (i == 4)
						{
							widthstr = std::string(1, inputstr[i - 2]) + std::string(1, inputstr[i - 1]);
						}
					}

					else if (lengthstr.length() == 2)
					{
						if (i == 4)
						{
							widthstr = std::string(1, inputstr[i - 1]);
						}
						else if (i == 5)
						{
							widthstr = std::string(1, inputstr[i - 2]) + std::string(1, inputstr[i - 1]);
						}
					}

					for (int x = i + 1; x < inputstr.length(); x++)
					{
						heightstr = heightstr + std::string(1, inputstr[x]);
					}

					break;
				}

				default:
					break;
				}

			}
		}

		length = std::stoi(lengthstr);
		width = std::stoi(widthstr);
		height = std::stoi(heightstr);
	}

	int AreaCalculation()
	{
		int surfaceArea = (2 * length * width) + (2 * length * height) + (2 * height * width);

		std::vector<int> forSorting{ length,width,height };
		std::sort(forSorting.begin(), forSorting.end());

		int clearanceArea =  forSorting[0] * forSorting[1];

		return (surfaceArea + clearanceArea);
	}

	int RibbonLengthCalculator()
	{
		std::vector<int> forSorting{ length,width,height };
		std::sort(forSorting.begin(), forSorting.end());

		int sideRibbonLength = (2 * forSorting[0]) + (2 * forSorting[1]);

		int bowLength = (length * width * height);

		return (sideRibbonLength + bowLength);
	}
};

