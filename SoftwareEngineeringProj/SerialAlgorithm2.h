#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <iostream>

class SerialAlgorithm {
public:
	using namePairs = std::list<std::pair<std::string, std::string>>;
	using indexPairs = std::list<std::pair<int, std::string>>;

	SerialAlgorithm() = default;
	SerialAlgorithm(std::string filepath);

	void GetLastNames();
	void SortByT();

private:
	namePairs F;
	namePairs H;
	indexPairs G;

	namePairs F1;
	indexPairs G1;

	int t = 1;
	int N = 0;
};