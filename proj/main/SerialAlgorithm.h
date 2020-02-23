#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <list>

class SerialAlgorithm {
public:
	SerialAlgorithm() = default;
	SerialAlgorithm(std::string filepath);

private:
	std::list<std::pair<std::string, std::string>> namePairs;
	std::list<std::pair<std::string, std::string >> finalOutput;

	std::list<std::pair<std::string, std::string >> a;
	std::list<std::pair<std::string, std::string >> b;
};