
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cctype>
# include <cstdlib>
# include <string>

class   Contact
{
    public:
        Contact();
        ~Contact();
        void    init(void);
        void    set_index(int i);
        void    print_contact(void);
        void    start_value(int index);
        void    disp_full_info(void);
    private:
        std::string _last_name;
        std::string _first_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
        int         _index;
        std::string _getInput(std::string str);
        void        _printinfo(std::string str);
};

#endif