#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _btcdata;
    public:
        //Orthodox 
        BitcoinExchange(void);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        //Members
        std::string read_data(std::ifstream &file);
        std::string read_input(std::string &input);
        int date_control(std::string str);
        int value_control(double value);
        int open_file(std::string av);
};
#endif