#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src ){
	*this = src;}

BitcoinExchange::~BitcoinExchange(){}


BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs ){
	if ( this != &rhs ) {
		this->map = rhs.map;
		this->map2 = rhs.map2;
	}
	return *this;
}


void BitcoinExchange::readData(std::string key, float value1, int year1, int month1, int day1){
	std::ifstream file("data.csv");
	std::string line;
	while (getline(file, line)){
		if (line == "date,exchange_rate")
			continue ;
		std::string date = line.substr(0, line.find(","));
    	std::string value = line.substr(line.find(",") + 1, line.length());
		map2[date] = atof(value.c_str());
	}
	std::map<std::string, float>::iterator it; 
	int year;
	int month;
	int day;
    for (it = map2.begin(); it != map2.end(); ++it) { 
		year = atoi(it->first.substr(0, it->first.find("-")).c_str());
        if (year == year1) {
			month = atoi(it->first.substr(it->first.find("-") + 1, it->first.find("-", it->first.find("-") + 1) - it->first.find("-") - 1).c_str());
			if (month == month1) {
				day = atoi(it->first.substr(it->first.find("-", it->first.find("-") + 1) + 1, it->first.length()).c_str());
				if (day == day1)
					break ;
			}}}
	int conta = 0;
	if (day != day1) {
		for (it = map2.begin(); it != map2.end(); ++it) { 
			year = atoi(it->first.substr(0, it->first.find("-")).c_str());
			if (year == year1) {
				month = atoi(it->first.substr(it->first.find("-") + 1, it->first.find("-", it->first.find("-") + 1) - it->first.find("-") - 1).c_str());
				if (month == month1) {
					day = atoi(it->first.substr(it->first.find("-", it->first.find("-") + 1) + 1, it->first.length()).c_str());
					if (day < day1) {conta = day;}
					else {break ;}
		}}}}
	int day2;
	for (it = map2.begin(); it != map2.end(); ++it) { 
		year = atoi(it->first.substr(0, it->first.find("-")).c_str());
        if (year == year1) {
			month = atoi(it->first.substr(it->first.find("-") + 1, it->first.find("-", it->first.find("-") + 1) - it->first.find("-") - 1).c_str());
			if (month == month1) {
				day2 = atoi(it->first.substr(it->first.find("-", it->first.find("-") + 1) + 1, it->first.length()).c_str());
				if (day2 == day || day2 == conta) {
					std::cout << key << " => " << value1 << " = " << value1 * it->second << std::endl; return ;}
	}}}
}
