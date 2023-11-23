#include "PmergeMe.hpp"

void fillVector(char **argv, int argc, std::vector<int> &vect) {

	for (int i = 1; i < argc; ++i) {
		if (std::atoi(argv[i]) < 0) {
			std::cerr << "Negative number not allowed" << std::endl;
			exit(2);
		}
		vect.push_back(std::atoi(argv[i]));
	}
}

void fillList(char **argv, int argc, std::list<int> &list) {
	for (int i = 1; i < argc; ++i) {
		if (std::atoi(argv[i]) < 0) {
			std::cerr << "Negative number not allowed" << std::endl;
			exit(2);
		}
		list.push_back(std::atoi(argv[i]));
	}
}

std::vector<int> returnLeft(std::vector<int> &vect, int middle) {
	std::vector<int> leftPart;
	for (int i = 0; i < middle; ++i) {  // middle n'est pas inclus
		leftPart.push_back(vect[i]);
	}
	return leftPart;
}

std::vector<int> returnRight(std::vector<int> &vect, int middle) {
	std::vector<int> rightPart;
	for (size_t i = middle; i < vect.size(); ++i) {  // commence à middle
		rightPart.push_back(vect[i]);
	}
	return rightPart;
}

void triFusionInsertionVect(std::vector<int> &vect) {
	if (vect.size() > 1) {
		int middle = vect.size() / 2;
		std::vector<int> leftVect = returnLeft(vect, middle);
		std::vector<int> rightVect = returnRight(vect, middle);

		triFusionInsertionVect(leftVect);
		triFusionInsertionVect(rightVect);

		fusionVect(leftVect, rightVect, vect);
	}
}

void fusionVect(const std::vector<int> &left, const std::vector<int> &right, std::vector<int> &vect) {
	size_t iLeft = 0, iRight = 0;

	vect.clear();
	vect.reserve(left.size() + right.size());

	while (iLeft < left.size() && iRight < right.size()) {
		if (left[iLeft] <= right[iRight]) {
			vect.push_back(left[iLeft++]);
		} else {
			vect.push_back(right[iRight++]);
		}
	}

	while (iLeft < left.size()) {
		vect.push_back(left[iLeft++]);
	}
	while (iRight < right.size()) {
		vect.push_back(right[iRight++]);
	}
}

void splitList(const std::list<int> &list, std::list<int> &left, std::list<int> &right) {
	std::list<int>::const_iterator it = list.begin();
	size_t middle = list.size() / 2;

	for (size_t i = 0; i < middle; ++i) {
		left.push_back(*it++);
	}
	for (; it != list.end(); ++it) {
		right.push_back(*it);
	}
}

void triFusionInsertionList(std::list<int> &list) {
	if (list.size() > 1) {
		std::list<int> leftList, rightList;
		splitList(list, leftList, rightList);

		triFusionInsertionList(leftList);
		triFusionInsertionList(rightList);

		list = fusionList(leftList, rightList);
	}
}

std::list<int> fusionList(const std::list<int> &left, const std::list<int> &right) {
	std::list<int> result;
	std::list<int>::const_iterator itLeft = left.begin(), itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end()) {
		if (*itLeft <= *itRight) {
			result.push_back(*itLeft++);
		} else {
			result.push_back(*itRight++);
		}
	}

	result.insert(result.end(), itLeft, left.end());
	result.insert(result.end(), itRight, right.end());

	return result;
}
