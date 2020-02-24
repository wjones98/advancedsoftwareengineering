/*
#include "SerialAlgorithm.h"

//http://www.cplusplus.com/reference/list/list/sort/
bool SortByFirst(const std::pair<std::string, std::string>& first, const std::pair<std::string, std::string>& second)
{
	unsigned int i = 0;
	while ((i < first.first.length()) && (i < second.first.length()))
	{
		if (tolower(first.first[i]) < tolower(second.first[i])) return true;
		else if (tolower(first.first[i]) > tolower(second.first[i])) return false;
		++i;
	}
	return (first.first.length() < second.first.length());
}

//http://www.cplusplus.com/reference/list/list/sort/
bool SortBySecond(const std::pair<std::string, std::string>& first, const std::pair<std::string, std::string>& second)
{
	unsigned int i = 0;
	while ((i < first.second.length()) && (i < second.second.length()))
	{
		if (tolower(first.second[i]) < tolower(second.second[i])) return true;
		else if (tolower(first.second[i]) > tolower(second.second[i])) return false;
		++i;
	}
	return (first.second.length() < second.second.length());
}

//http://www.cplusplus.com/reference/list/list/sort/
bool SortBySecondInt(const std::pair<int, std::string>& first, const std::pair<int, std::string>& second)
{
	unsigned int i = 0;
	while ((i < first.second.length()) && (i < second.second.length()))
	{
		if (tolower(first.second[i]) < tolower(second.second[i])) return true;
		else if (tolower(first.second[i]) > tolower(second.second[i])) return false;
		++i;
	}
	return (first.second.length() < second.second.length());
}


//http://www.cplusplus.com/reference/list/list/sort/
bool SortBySecondInt(const std::pair<int, std::string>& first, const std::pair<int, std::string>& second)
{
	unsigned int i = 0;
	while ((i < first.second.length()) && (i < second.second.length()))
	{
		if (tolower(first.second[i]) < tolower(second.second[i])) return true;
		else if (tolower(first.second[i]) > tolower(second.second[i])) return false;
		++i;
	}
	return (first.second.length() < second.second.length());
}

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

void SerialAlgorithm::DisplayList(std::list<std::pair<std::string, std::string>> list) {
	for (auto pair : list) {
		std::cout << pair.first << " : " << pair.second << std::endl;
	}
}


void SerialAlgorithm::DisplayJoin(std::list<std::pair<std::string, std::string>> list1, std::list<std::pair<std::string, std::string>> list2) {
	listPairs::iterator iterA = SerialAlgorithm::a.begin();
	listPairs::iterator iterB = SerialAlgorithm::b.begin();

	while (iterA != SerialAlgorithm::a.end() || iterB != SerialAlgorithm::b.end()) {
		std::pair<std::string, std::string>& namePairA = *iterA;
		std::pair<std::string, std::string>& namePairB = *iterB;
		std::cout << namePairA.first << " : " << namePairA.second << " - " << namePairB.first << " : " << namePairB.second << std::endl;
		iterA++, iterB++;
	}
}

void SerialAlgorithm::GetLastNames() {
	SerialAlgorithm::a = SerialAlgorithm::namePairs;
	SerialAlgorithm::b = SerialAlgorithm::a;

	a.sort(SortByFirst);	
	b.sort(SortBySecond);

	DisplayJoin(a, b);

	std::cout << "----> File F <----" << std::endl;

	listPairs::iterator iterA = SerialAlgorithm::a.begin();
	listPairs::iterator iterB = SerialAlgorithm::b.begin();



	while (iterA != SerialAlgorithm::a.end() || iterB != SerialAlgorithm::b.end()) {
		std::pair<std::string, std::string>& namePairA = *iterA;
		std::pair<std::string, std::string>& namePairB = *iterB;
		if (namePairA.first == namePairB.second) {
			SerialAlgorithm::f.push_back(std::make_pair(namePairB.first, namePairA.second));
			std::cout << namePairA.first << " : " << namePairB.first << std::endl;
			iterA++;
			iterB++;
		}
		else {
			if (std::distance(SerialAlgorithm::a.begin(), iterA) == std::distance(SerialAlgorithm::b.begin(), iterB))
			{
				SerialAlgorithm::finalOutput.push_back(std::make_pair(SerialAlgorithm::namePairs.size() - 1, namePairB.first));
				SerialAlgorithm::finalOutput.push_back(std::make_pair(SerialAlgorithm::namePairs.size(), namePairB.second));
				if (tolower(namePairA.first[0]) > tolower(namePairB.second[0])) {
					iterB++;
				}
				else {
					iterA++;
				}
			}
			else {
				iterA++;
			}
			
		}
	}

	std::cout << "----> File G <----" << std::endl;
	for (auto pair : SerialAlgorithm::finalOutput) {
		std::cout << pair.first << " : " << pair.second << std::endl;
	}
}

void SerialAlgorithm::SortByT() {
	//(z, z1)
	a = f;
	//(x, x1)
	SerialAlgorithm::b = SerialAlgorithm::a;
	SerialAlgorithm::g = SerialAlgorithm::finalOutput;
	b = a;

	a.sort(SortByFirst);
	b.sort(SortBySecond);
	g.sort(SortBySecondInt);
	DisplayJoin(a, b);

	g = finalOutput;
	std::list<std::pair<int, std::string >> g1;
	listPairs b1;

	listPairs::iterator iterA = SerialAlgorithm::a.begin();
	listPairs::iterator iterB = SerialAlgorithm::b.begin();
	
	std::list<std::pair<int, std::string >>::iterator iterG = SerialAlgorithm::g.begin();
	unsigned int t = 1;
	int count = 0;
	while (t < SerialAlgorithm::namePairs.size()) {
		iterA = SerialAlgorithm::a.begin();
		iterB = SerialAlgorithm::b.begin();
		iterG = SerialAlgorithm::g.begin();

		while (iterB != SerialAlgorithm::b.end()) {
	listPairs::iterator iterA = a.begin();
	listPairs::iterator iterB = b.begin();
	std::list<std::pair<int, std::string >>::iterator iterG = g.begin();

	signed int t = 1;
	while (t < namePairs.size()) {
		t = t * 2;
		iterA = a.begin();
		iterB = b.begin();
		iterG = g.begin();

		while (std::distance(g.begin(), iterG) != g.size() - 1) {
			std::pair<std::string, std::string> & namePairA = *iterA;
			std::pair<std::string, std::string> & namePairB = *iterB;
			//(y,y1)
			std::pair<int, std::string>& namePairG = *iterG;
			std::cout << "namePairB : " << namePairB.second << " : " << "namePairG   : " << namePairG.second << std::endl;
			if (namePairB.second == namePairA.first) {
				b1.push_back(std::make_pair(namePairB.first, namePairA.second));
				std::cout << namePairB.first << " : " << namePairA.second << std::endl;
				++iterA;
				++iterB;
			}
			else if (namePairB.second == namePairG.second) {
				g1.push_back(std::make_pair(namePairG.first - t, namePairB.first));
				std::cout << "Pushed back " << namePairG.first - t << " : " << namePairB.first << std::endl;
				++iterB;
				if (std::distance(g.begin(), iterG) != g.size() - 1) {
					++iterG;
				}
				
			}
			else if (namePairB.second > namePairG.second) {
				iterG++;
			}
			else if (namePairB.second > namePairA.first) {
				iterB++;
			}
		}

		g1.sort(SortBySecondInt);
		for (auto pair : g) {
			g1.push_back(pair);
				if (std::distance(g.begin(), iterG) != g.size() -1) {
					++iterG;
				}
			}
			else if (namePairB.second > namePairA.first) {
				++iterB;
			}
		}
		
		if (g.size() > 2) {
			g1.sort(SortBySecondInt);
			for (auto pair : g) {
				g1.push_back(pair);
			}
			g = g1;
		}
		b = b1;
		b1.clear();

		a.sort(SortByFirst);
		b.sort(SortBySecond);
	}
	std::cout << "----> Final Output <----" << std::endl;
	for (auto pair : finalOutput) {
		std::cout << pair.first << " : " << pair.second << std::endl;
	}


}

*/

