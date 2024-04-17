
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class   PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void hello(void);
        void add_contact(void);
        void search_contact(void);
        void    start(void);
        void    print_tab(void);
    private:
        Contact _contact[8];
};

#endif