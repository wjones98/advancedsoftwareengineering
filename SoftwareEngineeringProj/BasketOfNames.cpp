#include "BasketOfNames.h"
BasketOfNames::BasketOfNames(std::string filepath) {
	std::ifstream file;
	file.open(filepath);
	std::string line;

	std::pair<std::string, std::string> namesLine;
	std::stringstream ss;

	namesWest;
	namesEast;

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
	std::unordered_map<std::string, std::string>::iterator iterW = namesWest.begin();
	std::unordered_map<std::string, std::string>::iterator iterE = namesEast.begin();
	std::string Westcurrent = firstName;
	std::string Eastcurrent = firstName;
	std::string value;
	
	bool foundWesterly = false;
	bool foundEasterly = false;
	while (foundWesterly == false || foundEasterly == false) {
		if (!namesWest[Westcurrent].empty()) {
			value = namesWest[Westcurrent];
			ordered.push_back(value);
			Westcurrent = value;
			iterW++;
		}
		else {
			foundWesterly = true;
		}
		if (!namesEast[Eastcurrent].empty()) {
			value = namesEast[Eastcurrent];
			ordered.push_front(value);
			Eastcurrent = value;
			iterE++;
		}
		else {
			foundEasterly = true;
		}
	}

}

int main(int argc, char* argv[]) {
	BasketOfNames basket(argv[1]);
	basket.OrderList();
	for (auto name : basket.ordered) {
		std::cout << name << std::endl;
	}
}
