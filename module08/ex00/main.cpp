#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

bool triCroissant(int a, int b) {
	return (a < b);
}

bool triDecroissant(int a, int b) {
	return (a > b);
}

void afficherVecteur(std::vector<int> &vect) {
	for (size_t i = 0; i < vect.size(); ++i) {
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int>	initVector(int vectorSize) {
	std::vector<int> v;

	for (int i = 0; i < vectorSize; ++i) {
		v.push_back(i);
	}
	return v;
}

void	eraseEven(std::vector<int> &vect) {
	for (unsigned int i = 0; i < vect.size(); ++i) {
		if (vect[i] % 2 == 0)
			vect.erase(vect.begin() + i--);
	}
}

int 	vectorSum(std::vector<int> &vect) {
	int sum = 0;
	for (size_t i = 0; i < vect.size(); ++i) {
		sum += vect[i];
	}
	return sum;
}

double		vectorAverage(std::vector<int> &vect) {
	if (vect.empty())
		throw std::range_error("Vector empty");
	double avg;
	int sum = vectorSum(vect);
	avg = static_cast<double>(sum) / static_cast<double>(vect.size());

	return avg;
}

std::string	reversedString(std::string toReverse) {
	std::stack<char> reversedString;

	for (size_t i = 0; i < toReverse.size(); ++i) {
		reversedString.push(toReverse[i]);
	}
	for (size_t i = 0; i < toReverse.size(); ++i) {
		toReverse[i] = reversedString.top();
		reversedString.pop();
	}
	return toReverse;
}


int main(void) {
	std::vector<int> vect = initVector(46);

	//Tri croissant
	std::sort(vect.begin(), vect.end(), triCroissant);
	std::cout << "Tri croissant : " << std::endl;
	afficherVecteur(vect);

	//Tri decroissant
	std::sort(vect.begin(), vect.end(), triDecroissant);
	std::cout << "Tri decroissant : " << std::endl;
	afficherVecteur(vect);

	//Supprimer les valeurs paires
	eraseEven(vect);
	std::cout << "Suppr pairs : " << std::endl;
	afficherVecteur(vect);

	//Sum vector
	std::cout << "Vector sum : " << std::endl;
	std::cout << vectorSum(vect) << std::endl;

	//Avg vector
	std::cout << "Vector Avg : " << std::endl;
	std::cout << vectorAverage(vect) << std::endl;



	//======================================================//

	std::stack<char> pile;

	std::string toReverse = "Bonjour Les Gens !";
	toReverse = reversedString(toReverse);
	std::cout << toReverse << std::endl;


	return 0;
}