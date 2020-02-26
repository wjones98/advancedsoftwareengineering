// SoftwareEngineeringCoursework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
/*
#include <chrono>

#include "dictionary.h"
#include "SerialAlgorithm2.h"
#include <fstream>
#include <thread>
int main()
{
	std::ofstream resultsFile;
	std::list<std::string> testDataNames = { "20", "50", "100", "200", "500", "1K", "2K", "5K", "10K", "20K", "50K", "100K", "200K", "500K", "1M", "2M", "3M" };
	std::string filepath;
	for (int i = 0; i < 4; i++)
	{
		resultsFile.open("SerialResultsTest" + std::to_string(i) + ".csv");
		for (auto amount : testDataNames) {
			filepath = "E:\\GitHub\\advancedsoftwareengineering\\TestData\\input-papers-" + amount + ".txt";
			auto start = std::chrono::high_resolution_clock::now();
			SerialAlgorithm basket(filepath);
			basket.GetLastNames();
			basket.SortByT();
			auto elapsed = std::chrono::high_resolution_clock::now() - start;
			long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			std::cout << amount << " elapsed time: " << microseconds << std::endl;
			resultsFile << amount << "," << microseconds << std::endl;
		}
		resultsFile.close();
	}
	return 0;
}
*/
#include "SerialAlgorithm2.h"
int main(int argc, char* argv[]) {
	SerialAlgorithm basket(argv[1]);
	basket.GetLastNames();
	basket.SortByT();
	for (auto pair : basket.G) {
		std::cout << pair.second << std::endl;
	}
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
