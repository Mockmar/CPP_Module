
# include "ScalarConvert.hpp"

e_type is_spe_string(std::string str)
{
    if (str == "nan" || str == "nanf")
        return (TYPE_NAN);
    if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
        return (TYPE_INF_PLUS);
    if (str == "-inf" || str == "-inff")
        return (TYPE_INF_MINUS);
    return (TYPE_NOTHING);
}

bool    is_int(const char *str)
{
    int i;

    i = 0;
    if (str[0] && (str[0] == '-' || str[0] == '+'))
        i++;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool    is_char(const char *str)
{
    if (str[0] && str[1] == 0)
        if (isprint(str[0]))
            return (true);
    return (false);
}

bool    is_float(const char *str)
{
    int i;
    int cptpt = 0;

    i = 0;
    if (str[0] && (str[0] == '-' || str[0] == '+'))
        i++;
    while (str[i])
    {
        if (str[i] && str[i] == '.' && cptpt == 0 && str[i + 1] && str[i + 1] != 'f')
        {
            cptpt = 1;
            i++;
        }
        if (str[i] && str[i] == 'f' && str[i + 1] == 0 && cptpt == 1)
            return (true);
        if (str[i] && !isdigit(str[i]) && str[i + 1] != 0)
            return (false);
        i++;
    }
    return (false);
}

bool    is_double(const char *str)
{
    int i;
    int cptpt = 0;

    i = 0;
    if (str[0] && (str[0] == '-' || str[0] == '+'))
        i++;
    while (str[i])
    {
        if (str[i] && str[i] == '.' && cptpt == 0 && str[i + 1])
        {
            cptpt = 1;
            i++;
        }
        if (str[i] && !isdigit(str[i]))
            return (false);
        i++;
    }
    if (cptpt == 1)
        return (true);
    return (false);
}