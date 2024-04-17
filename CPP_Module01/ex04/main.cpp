
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    std::ifstream	in;
	std::ofstream	out;
    std::string     infile;
    std::string     outfile;
    std::string     line;
    std::string     s1;
    std::string     s2;
    int             len;
    int             len2;
    int             start;

    if (ac != 4 || !av[1][0] || !av[2][0] || !av[3][0])
    {
        std::cout << "Error arguments" << std::endl;
        return 1;
    }
    infile = av[1];
    in.open(infile.c_str(), std::ifstream::in);
    if (!in)
    {
        std::cout << "Error open input file" << std::endl;
        return 1;
    }
    outfile = infile + ".replace";
    out.open(outfile.c_str(), std::ifstream::out);
    if (!out)
    {
        in.close();
        std::cout << "Error open out file" << std::endl;
        return 1;
    }
    s1 = av[2];
    s2 = av[3];
    len = s1.length();
    len2 = s2.length();
    while (std::getline(in, line, '\0'))
    {
        start = line.find(s1);
        while (start != -1 )
        {
            line = line.substr(0, start) + s2 + line.substr(start + len);
            start = line.find(s1, start + len2);
        }
        out << line;
    }
    return (0);
}