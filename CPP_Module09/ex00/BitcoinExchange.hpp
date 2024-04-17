
#ifndef BITCOINEXCHANGE_hpp
# define BITCOINEXCHANGE_hpp

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& be);
		BitcoinExchange& operator=(const BitcoinExchange& be);
		BitcoinExchange(const std::string& file);
		~BitcoinExchange(void);

		void	add_date(const std::string& line);
        std::map<std::string, double> getTabPrices(void) const {return(tabPrices);}
        double  findPrice(std::string date);

	private:
		std::map<std::string, double> 	tabPrices;
};

std::string decremente_date(const std::string str);
bool bisextile(int year);
std::string trimString(std::string str);
bool isDateValid(std::string date);
bool isDecimalNumber(const std::string str);
bool check_DateRange(const std::string date);
bool checkFormat(std::string line);
void  extract_price(std::string line, BitcoinExchange &be);
void calcul_price(std::string file, BitcoinExchange &be);

#endif