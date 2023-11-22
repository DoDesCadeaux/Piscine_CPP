#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define NEG_NUMBER		"not a positive number."
#define LARGE_NUMBER	"too large number."
#define BAD_INPUT		"bad input => "

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

void displayMap(std::map<std::string, float> &datamap);
void displayFile(std::ifstream &displayifs);
std::map<std::string, float> fillMapCSV(std::ifstream &ifs);
void inputParsing(std::ifstream &inputFile, std::map<std::string, float> &datamap);
bool isValidLine(std::string &line);
bool checkSpecial(std::string &line);
std::string closestDate(const std::map<std::string, float>& datamap, const std::string& date);
std::string formatNumber(float taux);
std::string performExchange(const std::string &date, const std::string &closestdate, float &value, const std::map<std::string, float> &datamap);

#endif
