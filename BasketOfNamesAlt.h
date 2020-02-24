#pragma once
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

class BasketOfNamesAlt {
public:
	BasketOfNamesAlt() = default;
	BasketOfNamesAlt(std::string);

	void OrderList();

	std::list<std::string> ordered;

private:
	std::map<std::string, std::string> namesWest;
	std::map<std::string, std::string> namesEast;
};