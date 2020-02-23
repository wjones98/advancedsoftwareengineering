// SoftwareEngeeringProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "E:\GitHub\advancedsoftwareengineering\SerialAlgorithm.h"

int main()
{
	std::string filepath = "E:\\GitHub\\advancedsoftwareengineering\\input-papers-20.txt";
	SerialAlgorithm obj(filepath);
	
	obj.GetLastNames();
	obj.SortByT();
}


