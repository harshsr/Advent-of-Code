#include<iostream>
#include<string>
#include"MD5.h"
#include<thread>


void HashFinder(int& startingNumber, bool& foundHash)
{
	MD5 myMD5;
	std::string stringStart = "iwrupvqb";

	int maxNumber = 1250000; //125000 because we want to devide 1000000 into 8 threads

	for(int i = 0; i<maxNumber; i++)
	{
		std::string inputString = stringStart + std::to_string(startingNumber);
		inputString = myMD5(inputString);

		std::cout << "\n" << inputString;
		std::string hashStart = inputString.substr(0, 6);

		if (hashStart == "000000") {
			foundHash = true;
			return;
		}
		startingNumber++;
	}
}

int main()
{
	
	int startingPoint1 = 0;
	int startingPoint2 = 1250000;
	int startingPoint3 = 2500000;
	int startingPoint4 = 3750000;
	int startingPoint5 = 5000000;
	int startingPoint6 = 6250000;
	int startingPoint7 = 7500000;
	int startingPoint8 = 8750000;

	bool hash1 = false;
	bool hash2 = false;
	bool hash3 = false;
	bool hash4 = false;
	bool hash5 = false;
	bool hash6 = false;
	bool hash7 = false;
	bool hash8 = false;

	std::thread thread1(HashFinder, std::ref(startingPoint1), std::ref(hash1));
	std::thread thread2(HashFinder, std::ref(startingPoint2), std::ref(hash2));
	std::thread thread3(HashFinder, std::ref(startingPoint3), std::ref(hash3));
	std::thread thread4(HashFinder, std::ref(startingPoint4), std::ref(hash4));
	std::thread thread5(HashFinder, std::ref(startingPoint5), std::ref(hash5));
	std::thread thread6(HashFinder, std::ref(startingPoint6), std::ref(hash6));
	std::thread thread7(HashFinder, std::ref(startingPoint7), std::ref(hash7));
	std::thread thread8(HashFinder, std::ref(startingPoint8), std::ref(hash8));
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();
	thread6.join();
	thread7.join();
	thread8.join();

	if (hash1 == true)
	{
		std::cout << "\n\n" << startingPoint1;
	}
	if (hash2 == true)
	{
		std::cout << "\n\n" << startingPoint2;
	}
	if (hash3 == true)
	{
		std::cout << "\n\n" << startingPoint3;
	}
	if (hash4 == true)
	{
		std::cout << "\n\n" << startingPoint4;
	}
	if (hash5 == true)
	{
		std::cout << "\n\n" << startingPoint5;
	}
	if (hash6 == true)
	{
		std::cout << "\n\n" << startingPoint6;
	}
	if (hash7 == true)
	{
		std::cout << "\n\n" << startingPoint7;
	}
	if (hash8 == true)
	{
		std::cout << "\n\n" << startingPoint8;
	}
	
}