#include "SerialAlgorithm2.h"

bool SortByFirst(const std::pair<std::string, std::string>& first, const std::pair<std::string, std::string>& second)
{
	return first.first < second.first;
}


bool SortBySecond(const std::pair<std::string, std::string>& first, const std::pair<std::string, std::string>& second)
{
	return first.second < second.second;
}

bool SortBySecondInt(const std::pair<int, std::string>& first, const std::pair<int, std::string>& second)
{
	return first.second < second.second;
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
			F.push_back(namesLine);
		}
		file.close();
	}
	N = F.size();
}

void SerialAlgorithm::GetLastNames() {
	H = F;
	H.sort(SortByFirst);
	F.sort(SortBySecond);

	namePairs::iterator iterH = H.begin();
	namePairs::iterator iterF = F.begin();

	while (iterH != H.end() && iterF != F.end()) {
		if (iterF->second == iterH->first) {
			F1.push_back(std::make_pair(iterF->first, iterH->second));
			++iterF, ++iterH;
		}
		else if (iterF->second > iterH->first) {
			++iterH;
		}
		else {
			G.push_back(std::make_pair(N - 1, iterF->first));
			G.push_back(std::make_pair(N, iterF->second));
			++iterF;
		}
	}
	G.sort(SortBySecondInt);
	F = F1;
	F1.clear();
}

void SerialAlgorithm::SortByT() {
	while (t <= N) {

		H = F;
		H.sort(SortByFirst);
		F.sort(SortBySecond);

		namePairs::iterator iterH = H.begin();
		namePairs::iterator iterF = F.begin();
		indexPairs::iterator iterG = G.begin();
		t = t * 2;
		while (iterF != F.end()) {
			if (iterF->second == iterH->first) {
				F1.push_back(std::make_pair(iterF->first, iterH->second));
				++iterF, ++iterH;
			}
			else if (iterG != G.end() && iterF->second == iterG->second) {
				G1.push_back(std::make_pair(iterG->first - t, iterF->first));
				++iterF, ++iterG;
			}
			else if (iterG != G.end() && iterF->second > iterG->second) {
				++iterG;
			}
			else if (iterF->second > iterH->first) {
				++iterH;
			}
		}
		G1.sort(SortBySecondInt);
		G1.merge(G, SortBySecondInt);
		G = G1;
		F = F1;
		F1.clear();
	}
	G.sort();
	G.unique();
}