#include "SerialAlgorithm2.h"

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
	H.sort();
	F.sort(SortBySecond);

	namePairs::iterator iterH = H.begin();
	namePairs::iterator iterF = F.begin();

	while (iterH != H.end() && iterF != F.end()) {
		std::cout << iterH->first << " : " << iterH->second
			<< " - " << iterF->first << " : " << iterF->second << std::endl;

		if (iterH->first == iterF->second) {
			std::cout << iterF->first << " : " << iterH->second << std::endl;
			F1.push_back(std::make_pair(iterF->first, iterH->second));
			++iterH, ++iterF;
		}
		else {
			if (std::distance(SerialAlgorithm::H.begin(), iterH) == std::distance(SerialAlgorithm::F.begin(), iterF)) {
				std::cout << N - 1 << " : " << iterF->first << std::endl;
				G.push_back(std::make_pair(N - 1, iterF->first));
				std::cout << N << " : " << iterF->second << std::endl;
				G.push_back(std::make_pair(N, iterF->second));
				if (iterH->first > iterF->second) {
					iterF++;
				}
				else {
					iterH++;
				}
			}
			else {
				++iterH;
			}
		}
	}
	std::cout << "Size of F1 " << F1.size() << " : " << "Size of N " << N << std::endl;
	std::cout << "Size of G " << G.size() << std::endl;
	F = F1;
	F1.clear();
}

void SerialAlgorithm::SortByT() {
	std::cout << "------------------------------------------------------" << std::endl;
	while (t <= N) {

		H = F;
		H.sort();
		F.sort(SortBySecond);

		namePairs::iterator iterH = H.begin();
		namePairs::iterator iterF = F.begin();
		indexPairs::iterator iterG = G.begin();
		t = t * 2;
		std::cout << t << std::endl;
		while (iterF != F.end()) {
			std::cout << iterH->first << " : " << iterH->second
				<< " - " << iterF->first << " : " << iterF->second << std::endl;

			if (iterF->second == iterH->first) {
				std::cout << iterF->first << " : " << iterH->second << std::endl;
				F1.push_back(std::make_pair(iterF->first, iterH->second));
				++iterF, ++iterH;
			}
			else if (iterG != G.end() && iterF->second == iterG->second) {
				std::cout << iterG->first - t << " : " << iterF->first << std::endl;
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
		std::cout << "------------------------------------------------------" << std::endl;
		G1.sort(SortBySecondInt);
		G1.merge(G, SortBySecondInt);
		G = G1;
		F = F1;
		F1.clear();
		std::cout << G.size() << std::endl;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	G.sort();
	G.unique();
	for (auto pair : G) {
		std::cout << pair.first << " : " << pair.second << std::endl;
	}
}