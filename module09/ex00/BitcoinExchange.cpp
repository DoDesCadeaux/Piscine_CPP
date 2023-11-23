#include "BitcoinExchange.hpp"

void displayMap(std::map<std::string, float> &datamap) {
	for (std::map<std::string, float>::iterator it = datamap.begin(); it != datamap.end(); ++it) {
		std::cout << "Date: " << it->first << " Valeur: " << it->second << std::endl;
	}
	std::cout << "====================================" << std::endl;
}

void displayFile(std::ifstream &displayifs) {
	std::string line;
	while (std::getline(displayifs, line))
		std::cout << line << std::endl;
}

std::map<std::string, float> fillMapCSV(std::ifstream &ifs) {
	std::map<std::string, float> datamap;
	std::string tmp;
	std::string line;
	if (!std::getline(ifs, tmp))
		throw std::runtime_error("First line read error");

	while (std::getline(ifs, line)) {
		std::string date = line.substr(0, line.find(','));
		float value = atof(line.substr(line.find(',') + 1).c_str());
		datamap[date] =  value;
	}
	return datamap;
}

bool isLeapYear(int year) {
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool isValidDate(std::string &date) {
	int year, month, day;
	char delim1, delim2;

	std::stringstream dateStream(date);

	dateStream >> year >> delim1 >> month >> delim2 >> day;

	if (delim1 != '-' || delim2 != '-')
		return false;
	if (year < 2009 || month < 1 || day < 1 || month > 12 || year > 2022)
		return false;
	if (year == 2022 && month == 3 && day > 29)
		return false;
	if (year == 2022 && month > 3)
		return false;
	if (year == 2009 && month == 1 && day < 2)
		return false;

	int daysInMonth[] = { 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (day <= daysInMonth[month - 1]);
}

bool tooManySpecials(std::string &line) {
		long countDot = std::count(line.begin(), line.end(), '.');
		long countDash = std::count(line.begin(), line.end(), '-');
		long countPipe = std::count(line.begin(), line.end(), '|');
		long countSpace = std::count(line.begin(), line.end(), ' ');

		if (countDash > 3 || countDot > 1 || countPipe > 1 || countSpace > 2) {
			return true;
		}

		return false;
}

bool checkLine(std::string &line) {
	if (line.empty())
		return false;
	char autorisedToken [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '|', ' ', '-', '.'};
	if (tooManySpecials(line))
		return false;
	for (unsigned long it = 0; it < line.size() ; ++it) {
		for (size_t j = 0; j < sizeof(autorisedToken); j++) {
			if (line[it] == autorisedToken[j])
				break;
			if (j == sizeof(autorisedToken) - 1)
				return false;
		}
	}
	return true;
}

int isValidValue(std::string &value) {
	float fvalue = atof(value.c_str());
	if (fvalue < 1)
		return 1;
	else if (fvalue > 1000)
		return 2;
	return 0;
}

bool isValidLine(std::string &line) {

	if (!checkLine(line))
		return false;

	std::string date = line.substr(0, line.find('|') - 1);
	if (!isValidDate(date)) {
		std::cout << "Error: " << BAD_INPUT << date << std::endl;
		return false;
	}
	std::string value = line.substr(line.find('|') + 2);
	if (isValidValue(value) == 1) {
		std::cout << "Error: " <<  NEG_NUMBER << std::endl;
		return false;
	}
	else if (isValidValue(value) == 2) {
		std::cout << "Error: " <<  LARGE_NUMBER << std::endl;
		return false;
	}
	return true;
}

void inputParsing(std::ifstream &inputFile, std::map<std::string, float> &datamap) {
	std::string line;
	std::string tmp;

	if (std::getline(inputFile, tmp))
		if (tmp != "date | value")
			throw std::runtime_error("Bad file description");
	while (std::getline(inputFile, line)) {
		if (!isValidLine(line))
			continue;
		else {
			std::string inputdate = line.substr(0, line.find('|') - 1);
			std::string closestdate = closestDate(datamap, line.substr(0, line.find('|') - 1));
			if (closestdate == "Aucune date")
				throw std::runtime_error("Invalid date");
			float value = atof(line.substr(line.find('|') + 2).c_str());
			std::cout << performExchange(inputdate, closestdate, value, datamap) << std::endl;
		}
	}
}

std::string closestDate(const std::map<std::string, float> &datamap, const std::string &date) {
	std::map<std::string, float>::const_iterator it = datamap.find(date);

	if (it != datamap.end()) {
		return it->first; //Date exacte
	} else {
		for (it = datamap.lower_bound(date); it != datamap.begin(); --it) {
			if (it->first < date) {
				return it->first; //Date juste avant
			}
		}
	}

	return "Aucune date"; //Aucune date
}

std::string formatNumber(float valeur) {
	std::ostringstream oss;

	// Fixer la précision à 2 décimales
	oss << std::fixed << std::setprecision(2) << valeur;

	std::string resultat = oss.str();

	// Supprimer les zéros inutiles et le point si nécessaire
	size_t decimale = resultat.find('.');
	if (decimale != std::string::npos) {
		// Supprime les zéros inutiles
		resultat.erase(resultat.find_last_not_of('0') + 1, std::string::npos);

		// Supprime le point si c'était le dernier caractère
		if (resultat[resultat.size() - 1] == '.') {
			resultat.erase(decimale, std::string::npos);
		}
	}

	return resultat;
}

std::string performExchange(const std::string &date, const std::string &closestdate, float &value, const std::map<std::string, float> &datamap) {
	std::map<std::string, float>::const_iterator it = datamap.find(closestdate);

	if (it != datamap.end())
		return (date + " => " + formatNumber(value) + " = " + formatNumber(it->second * value));
	else
		return "";
}
