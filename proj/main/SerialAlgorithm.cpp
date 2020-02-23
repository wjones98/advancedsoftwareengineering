#include "SerialAlgorithm.h"

SerialAlgorithm::SerialAlgorithm(std::string filepath) {
	std::ifstream file;
	file.open(filepath);
	std::string line;

	std::pair<std::string, std::string> namesLine;
	std::stringstream ss;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			ss << line;
			std::getline(ss, namesLine.first, ',');
			std::getline(ss, namesLine.second, ',');
			ss.clear();
			namePairs.push_back(namesLine);
		}
		file.close();
	}
}

