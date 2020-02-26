#pragma once
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <iostream>

class BasketOfNames {
public:
	BasketOfNames() = default;
	BasketOfNames(std::string);

	void OrderList();

	std::list<std::string> ordered;

private:
	std::unordered_map<std::string, std::string> namesWest;
	std::unordered_map<std::string, std::string> namesEast;
};

