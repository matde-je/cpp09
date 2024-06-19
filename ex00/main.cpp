#include "BitcoinExchange.hpp"

void BitcoinExchange::parsing(std::string path) {
    try {
        std::ifstream file(path.c_str());
        std::string line;
        int a = 0;
        while (getline(file, line)){
            std::string key;
            std::string value;
            int trig = 0;
            int count = 0;
            int count4 = 0;
            int count3 = 0;
            int count2 = 0;
            if (line == "date | value") {a++;}
            if (a > 1) {std::cerr << "Error: invalid date | value.\n"; continue ;}
            for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
                if (*it == 'f') {count++;}
                if (*it == '.') {count2++;}
                if (*it == '|') {count3++;}
                if (*it == '-') {count4++;}
                if (isalpha(*it) && *it != 'f') {trig = 1;}
                if (std::isupper(*it) || ((*it == '|' && (*(it + 1) != ' ' || *(it - 1) != ' ')) || \
                    (*it == ' ' && *(it + 1) == ' ')) || (*it) == '\t' || (*it != '-' && *it != '.' \
                    && *it != 'f' && *it != '|' && !isdigit(*it) && line != "date | value" && *it != ' ')) {
                    count = 2; break ;}
            }
            if (count > 1 || count2 > 1 || count3 > 1 || count4 > 3) {std::cerr << "Error: bad input.\n"; continue ;}
            if (trig == 0){
                key = line.substr(0, line.find("|"));
                value = line.substr(line.find("|") + 1, line.length());
                map[key] = atof(value.c_str());
                this->parsing_date(key, value);}
        }}
    catch (...) {std::cerr << "Error parsing.\n";}
}



void BitcoinExchange::parsing_date(std::string key, std::string value) {

    int b = 0;
    for (int i = 0; i < (int)key.length(); i++)
        if (key[i] == '-') {b++;}
    if (b > 2) {std::cerr << "Error: invalid date '-'.\n"; return ;}
    std::string year = key.substr(0, key.find("-"));
    std::string month = key.substr(key.find("-") + 1, key.find("-", key.find("-") + 1) - key.find("-") - 1);
    std::string day = key.substr(key.find("-", key.find("-") + 1) + 1, key.length());
    for (int i = 0; i < (int)year.length(); i++)
        if (isspace(year[i])) {std::cerr << "Error in year"<< ".\n"; return ;}
    for (int i = 0; i < (int)month.length(); i++)
        if (isspace(month[i])) {std::cerr << "Error in month .\n"; return ;}
    for (int i = 0; i < (int)day.length(); i++)
        if (isspace(day[i]) && i < (int)day.length() - 1) {std::cerr << "Error in day.\n"; return ;}
    int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (atoi(day.c_str()) > month_limits[atoi(month.c_str()) - 1] || atoi(day.c_str()) < 1)
        {std::cerr << "Error: out of month range.\n"; return ;}
    if (atoi(year.c_str()) > 2022 || atoi(year.c_str()) < 2009 || atoi(month.c_str()) > 12 || atoi(month.c_str()) < 1) 
        {std::cerr << "Error: out of range date.\n"; return ;}
    if (atoi(year.c_str()) == 2022 && atoi(month.c_str()) > 3)
        {std::cerr << "Error: invalid 2022 date, no month corresponding.\n"; return ;}
    if (atoi(year.c_str()) == 2009 && atoi(month.c_str()) == 1 && atoi(day.c_str()) == 1)
        {std::cerr << "Error: invalid 2009 date, no day corresponding.\n"; return ;}
    if ( strtod(value.c_str(), NULL) > 1000 || strtod(value.c_str(), NULL) < -std::numeric_limits<int>::max() || strtod(value.c_str(), NULL) > std::numeric_limits<int>::max()) 
        {std::cerr << "Error: out of range value.\n"; return ;}
    if (strtod(value.c_str(), NULL) < 0) 
        {std::cerr << "Error: not a positive number.\n"; return ;}
    this->readData(key, atof(value.c_str()), atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str()));
}




int main(int argc, char **argv){
    if (argc != 2) {
        std::cerr << "Error in number of arguments.\n"; return 1;}
    BitcoinExchange a;
    a.parsing(argv[1]);
}
