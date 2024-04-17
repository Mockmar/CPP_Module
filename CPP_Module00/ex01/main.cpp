
#include "PhoneBook.hpp"

int main(void)
{
	bool run;
	std::string command;
    PhoneBook Book;

	run = true;
    Book.start();
	while (run)
	{
		std::cout << ">" << std::flush;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (1);
		if (command == "ADD")
			Book.add_contact();
		else if (command == "SEARCH")
			Book.search_contact();
		if (command == "EXIT")
		{
			std::cout << "exit" << std::endl;
			run = false;
		}
	}
	return (0);
}