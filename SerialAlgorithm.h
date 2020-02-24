/*
#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <iostream>

class SerialAlgorithm {
public:
	using listPairs = std::list<std::pair<std::string, std::string>>;

	SerialAlgorithm() = default;
	SerialAlgorithm(std::string filepath);

	void DisplayList(std::list<std::pair<std::string, std::string>>);

	void DisplayJoin(std::list<std::pair<std::string, std::string>>, std::list<std::pair<std::string, std::string>>);

	void GetLastNames();

	void SortByT();

	listPairs namePairs;
	std::list<std::pair<int, std::string >> finalOutput;
	std::list<std::pair<int, std::string >> g;

	listPairs a;
	listPairs b;
	listPairs f;
};
*/