
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::start(void)
{
    this->hello();
    for (size_t i = 0; i < 8; i++)
    {
        this->_contact[i].start_value(i);
    } 
}

void    PhoneBook::hello(void)
{
    std::cout<<"-----Welcome to your PhoneBook-----"<<std:: endl;
    std::cout<<"--------------Command--------------"<<std:: endl;
    std::cout<<"ADD     : to add a contact"<<std:: endl;
    std::cout<<"SEARCH  : to search for a contact"<<std:: endl;
    std::cout<<"EXIT    : to quite the phonebook"<<std:: endl;
    std::cout<<"-----------------------------------"<<std:: endl;
}

void    PhoneBook::add_contact(void)
{
    static int  i;

    this->_contact[i % 8].init();
    this->_contact[i % 8].set_index(i % 8);
    i++;
}

void    PhoneBook::search_contact(void)
{
    int index;
    bool OK;
    std::string tmp;

    OK = false;
    index = -1;
    this->print_tab();
    while (!OK)
    {
        std::cout<<"Enter index of contact : "<<std:: flush;
        std::cin>> index;
        if (std::cin.eof())
			exit(1);
        if (std::cin.good() && (index >= 0 && index < 8))
        {
            this->_contact[index].disp_full_info();
            OK = true;
        }
        else
        {
            std::cin.clear();
            std::cout<<"Bad index please retry"<<std:: endl;
        }
	    std::getline(std::cin, tmp);
    }
}

void    PhoneBook::print_tab(void)
{
    std::cout<<"---------------------------------------------"<<std:: endl;
    std::cout<<"|index     |first name|last name |nickname  |"<<std:: endl;
    std::cout<<"---------------------------------------------"<<std:: endl;
    for (size_t i = 0; i < 8; i++)
    {
        this->_contact[i].print_contact();
    }
}