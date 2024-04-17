
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& be)
{
	*this = be;
}

BitcoinExchange::BitcoinExchange(const std::string& file)
{
	std::string		line;
	std::ifstream	infile(file.c_str());

	if (infile.is_open())
	{
		std::getline(infile, line);
		while (infile)
		{
			std::getline(infile, line);
			if (line[0] != 0)
				add_date(line);
		}
	}
	else
	{
		throw std::runtime_error("Error: could not open file.");
	}
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& be)
{
	if (this != &be) 
    {
		tabPrices = be.tabPrices;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

void	BitcoinExchange::add_date(const std::string& line)
{
	size_t	i = 0;
	std::string	date;
	std::string	price_str;
	double		price;

	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == 0)
		return;
	date = line.substr(0, i);
	price_str = line.substr(i + 1);
	price = std::atof(price_str.c_str());
	tabPrices.insert(std::pair<std::string, double>(date, price));
}

double  BitcoinExchange::findPrice(std::string date)
{
    std::map<std::string, double>::iterator it = tabPrices.find(date);
    if (it == tabPrices.end())
        return (findPrice(decremente_date(date)));
    return (it->second);
}

/************************************************************************************/

std::string decremente_date(const std::string date)
{
    std::istringstream iss(date);
    int year, month, day;
    char separator1, separator2;
    iss >> year >> separator1 >> month >> separator2 >> day;

    if (day > 1)
        day--;
	else
	{
        if (month > 1)
		{
            month--;
            day = 31;
        }
		else
		{
            year--;
            month = 12;
            day = 31;
        }
    }
    std::ostringstream oss;
    oss << year << separator1 << std::setw(2) << std::setfill('0') << month << separator2
        << std::setw(2) << std::setfill('0') << day;
    return(oss.str());
}

bool bisextile(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

std::string trimString(std::string str)
{
	std::string trim = "";

	for (size_t i = 0; i < str.size(); i++)
	{
		if (std::isprint(str[i]))
			trim += str[i];
	}
	return (trim);
}

bool isDateValid(std::string date)
{
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    switch (month)
    {
        case 2:
            if (bisextile(year))
                return (day <= 29);
            else
                return (day <= 28);
        case 4:
        case 6:
        case 9:
        case 11:
            return (day <= 30);
        default:
            return (day <= 31);
    }
}

bool isDecimalNumber(const std::string str)
{
    std::istringstream iss(str);
    double value;
    return (iss >> value) && iss.eof();
}

bool check_DateRange(const std::string date)
{
    std::string minDateStr = "2009-01-02";
    std::string maxDateStr = "2022-03-29";

    return (date >= minDateStr && date <= maxDateStr);
}

bool checkFormat(std::string line)
{
	std::string format = "AAAA-MM-JJ | ";
	size_t i;

	if (line.size() < format.size())
		return false ;
	for ( i = 0; i < format.size(); i++)
	{
		if (format[i] == 'A' && !std::isdigit(line[i]))
			return false ;
		else if (format[i] == 'M' && !std::isdigit(line[i]))
			return false ;		
		else if (format[i] == 'J' && !std::isdigit(line[i]))
			return false ;
		else if ((format[i] == ' ' || format[i] == '-' || format[i] == '|') && format[i] != line[i])
			return false ;
	}
	if (!isDecimalNumber(trimString(line.substr(i, line.size()))))
		return false;
	return true ;
}

void  extract_price(std::string line, BitcoinExchange &be)
{
    std::string        	date;
    double      		value;

	if (!checkFormat(line))
		throw std::runtime_error("Error: bad input => " + trimString(line));
    date = line.substr(0, 10);
	if (!check_DateRange(date))
		throw std::runtime_error("Error: date out of range.");
	if (!isDateValid(date))
		throw std::runtime_error("Error: date doesn't exist.");
    value = std::atof(line.substr(13, line.size()).c_str());
	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
    std::cout<< date << " => " << value << " = " << be.findPrice(date) * value << std::endl;
}

void calcul_price(std::string file, BitcoinExchange &be)
{
	std::string		line;
	std::ifstream	infile(file.c_str());

	if (infile.is_open())
	{
		std::getline(infile, line);
		if (line.empty())
			throw std::runtime_error("Error: file is empty.");
		if (trimString(line) != "date | value")
			throw std::runtime_error("Error: bad format.");
		while (infile)
		{
			std::getline(infile, line);
			if (line[0] != 0)
            {
                try
                {
                    extract_price(line, be);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what() << std::endl;
                }
				if (infile.eof())
					return ;
            }
		}
	}
	else 
	{
		throw std::runtime_error("Error: could not open file.");
	}
}