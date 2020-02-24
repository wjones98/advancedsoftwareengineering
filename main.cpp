// SoftwareEngineeringCoursework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "dictionary.h"
#include "C:\Users\wajon\OneDrive\Documents\GitHub\advancedsoftwareengineering\SoftwareEngineeringProj\SerialAlgorithm2.h"

int main()
{
	std::string filepath = "C:\\Users\\wajon\\OneDrive\\Documents\\GitHub\\advancedsoftwareengineering\\input-papers-20.txt";
	SerialAlgorithm yeet(filepath);
	yeet.GetLastNames();
	yeet.SortByT();
	return 0;
}