// SoftwareEngineeringCoursework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dictionary.h"


int main()
{

	Containers::Dictionary<std::string, std::string> dict;
	dict.insert("WAJ", "Will");
	dict.insert("PaPaLingLing", "Usama");
	std::cout << *dict.lookup("WAJ") << std::endl;
	dict.remove("WAJ");
	std::cout << dict.lookup("WAJ") << std::endl;
	dict.displayList();
	//dict.displayList();
	//std::cout << "------------------------------------------------------------------" << std::endl;
	//
	//Containers::Dictionary<std::string, std::string> dict2;
	//dict2.insert("mixer", "Lydia");
	//dict2.insert("t=t", "Borth");
	//dict2.displayList();
	//std::cout << "------------------------------------------------------------------" << std::endl;

	//dict = std::move(dict2);

	//dict.displayList();
	//std::cout << "------------------------------------------------------------------" << std::endl;
	//dict2.insert("hello", "there");
	//dict2.displayList();
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
