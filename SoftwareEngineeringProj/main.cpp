// SoftwareEngineeringCoursework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

#include "dictionary.h"
#include "BasketOfNames.h"
#include <fstream>
#include <thread>
int main()
{
	std::ofstream resultsFile;
	std::list<std::string> testDataNames = { "50", "1M", "2K", "2M", "3M", "5K", "10K", "1K", "20K", "20", "50K", "100", "100K", "200", "200K", "500", "500K" };
	std::string filepath;
	for (int i = 0; i < 10; i++)
	{
		resultsFile.open("BasketAltResultsTest" + std::to_string(i) + ".csv");
		for (auto amount : testDataNames) {
			filepath = "C:\\Users\\wajon\\OneDrive\\Documents\\GitHub\\advancedsoftwareengineering\\TestData\\input-papers-" + amount + ".txt";
			auto start = std::chrono::high_resolution_clock::now();
			BasketOfNames basket(filepath);
			basket.OrderList();
			auto elapsed = std::chrono::high_resolution_clock::now() - start;
			long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			std::cout << amount << " elapsed time: " << microseconds << std::endl;
			resultsFile << amount << "," << microseconds << std::endl;
		}
		resultsFile.close();
	}

	
	return 0;
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
