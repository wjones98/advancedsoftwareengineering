#include "BasketOfNames.h"

BasketOfNames::BasketOfNames(std::string filepath) {
	std::ifstream file;
	file.open(filepath);
	std::string line;

	std::pair<std::string, std::string> namesLine;
	std::stringstream ss;

	BasketOfNames::namesWest;
	BasketOfNames::namesEast;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			ss << line;
			std::getline(ss, namesLine.first, ',');
			std::getline(ss, namesLine.second, ',');
			ss.clear();
			namesWest.insert(std::make_pair(namesLine.first, namesLine.second));
			namesEast.insert(std::make_pair(namesLine.second, namesLine.first));
		}
		file.close();
	}
}

void BasketOfNames::OrderList() {
	std::string firstName = namesWest.begin()->first;

	ordered.push_back(firstName);

	std::string current = firstName;

	for (int i = 0; i < namesWest.size(); i++) {
		if (!namesWest[current].empty()) {
			std::string value = namesWest[current];
			BasketOfNames::ordered.push_back(value);
			current = value;
		}
	}
	
	current = firstName;

	for (int i = 0; i < namesEast.size(); i++) {
		if (!namesEast[current].empty()) {
			std::string value = namesEast[current];
			BasketOfNames::ordered.push_front(value);
			current = value;
		}
	}
}

