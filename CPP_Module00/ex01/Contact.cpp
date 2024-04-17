
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str)
{
    std::string input = "";
    bool        OK;

    OK = false;
    while (!OK)
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.eof())
			exit(1);
        if (std::cin.good() && !input.empty())
        {
            OK = true;
            if (isspace(input[0]))
            {
                OK = false;
                std::cout << "Don't begin by a white space; please try again." << std::endl;    
            }
            else if (isspace(input[input.length() - 1]))
            {
                OK = false;
                std::cout << "Don't finish by a white space; please try again." << std::endl;    
            }
        }
        else
        {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    }
    return (input);
}

void    Contact::init(void) 
{
    this->_first_name = this->_getInput("Please enter you first name: ");
    this->_last_name = this->_getInput("Please enter your last name: ");
    this->_nickname = this->_getInput("Please enter your nickname: ");
    this->_phone_number = this->_getInput("Please enter your phone number: ");
    this->_darkest_secret = this->_getInput("Please enter your darkest secret: ");
}

void    Contact::start_value(int index) 
{
    this->_first_name = "";
    this->_last_name = "";
    this->_nickname = "";
    this->_phone_number = "";
    this->_darkest_secret = "";
    this->_index = index;
}

void    Contact::set_index(int i) 
{
    this->_index = i;
}

void    Contact::print_contact(void) 
{
    if (this->_first_name != "")
    {
        std::cout << "|" << this->_index << "         |" << std::flush;
        this->_printinfo(this->_first_name);
        std::cout << "|" << std::flush;
        this->_printinfo(this->_last_name);
        std::cout << "|" << std::flush;
        this->_printinfo(this->_nickname);
        std::cout<< "|" <<std::endl;
        std::cout<<"---------------------------------------------"<<std:: endl;
    }
}

void    Contact::disp_full_info(void)
{
    if (this->_first_name != "")
    {
        std::cout << "Index : " << this->_index << std::endl;
        std::cout << "Last name : " << this->_last_name << std::endl;
        std::cout << "First name : " << this->_first_name << std::endl;
        std::cout << "Nickname : " << this->_nickname << std::endl;
        std::cout << "Phone number : " << this->_phone_number << std::endl;
        std::cout << "Darkest secret : " << this->_darkest_secret << std::endl;
    }
    else
        std::cout << "contact doesn't exist" << std::endl;
}

void    Contact::_printinfo(std::string str)
{
    int i = 0;

    if (str.length() > 10)
    {
        for (i = 0; i < 9; i++)
            std::cout << (char)str[i] << std::flush;
        std::cout << "." << std::flush;  
    }
    else
    {
        while (str[i])
        {
            std::cout << (char)str[i] << std::flush;
            i++;
        }
        while (i<10)
        {
            std::cout << " " << std::flush;
            i++;
        }
    }  
}
