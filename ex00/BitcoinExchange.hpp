#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <cstdlib>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );
		void parsing(std::string av);
		void parsing_date(std::string key, std::string value);
		void readData(std::string key, float value, int year, int month, int day);
		std::map<std::string, float> map;
		std::map<std::string, float> map2;

	private:

};

void parsing_date(std::string key, std::string value);
#endif /* ************************************************* BITCOINEXCHANGE_H */