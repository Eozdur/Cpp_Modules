#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_btcdata = other._btcdata;
    }
    return *this;
}

int BitcoinExchange::open_file(std::string av)
{
    std::ifstream data_file;
    std::ifstream input_file(av.c_str());
    std::string line,data;
    data_file.open("data.csv");
    if (!data_file.is_open())
    {
        throw std::runtime_error("Error: data.csv file not found");
    }
    else
    {
        read_data(data_file);
    }
    if(!input_file)
    {
        throw std::runtime_error("Error: input file not found");
    }
    else
    {
        std::string firstline;
        getline(input_file,firstline);
        if(firstline != "date | value")
            throw std::runtime_error("First line must be 'date | value' !");
        std::cout << "Input file opened" << std::endl;
        while(getline(input_file, line))
        {
            this->read_input(line);
        }
    }
    data_file.close();
    input_file.close();
    return 0;
}

std::string BitcoinExchange::read_data(std::ifstream &file)
{
    std::cout << "File opened" << std::endl;
    std::string line,date,value;
    getline(file, line);
    while(!file.eof())
    {
        getline(file, line);
        std::stringstream ss(line);
        getline(ss, date, ',');
        getline(ss, value);
        this->_btcdata[date] = atof(value.c_str());
    }
    return line;
}

std::string BitcoinExchange::read_input(std::string &input)
{
    std::string line;
    std::string result;
    std::string date;
    double amount = 0.0;
    

    size_t found = input.find('|');
    amount = atof(input.substr(found + 1).c_str());
    date = input.substr(0, found - 1);
    if(found == std::string::npos)
    {
        std::cout << "Error: bad input => " << input << std::endl;
        return result;
    }
    if(date_control(date) == 1 || value_control(amount) == 1)
    {
        return result;
    }
    if(!input.empty())
    {
        std::map<std::string,double>::iterator it = this->_btcdata.find(date.c_str());
        std::map<std::string,double>::iterator beginit = this->_btcdata.begin();
        beginit++; 
        if(it != this->_btcdata.end())
        {
             std::cout << date << " => " << amount <<" * " <<it->second << " = " << it->second * amount << std::endl;
        }
        else if (it != this->_btcdata.begin())
        {
            it = this->_btcdata.lower_bound(date.c_str());
            if(it != beginit)
            {
                it--;
                std::cout << date << " => " << amount <<" * " <<it->second << " = " << it->second * amount << std::endl;
            }
            else
                std::cerr << "Error: no data found for date " << date << std::endl;

        }
    }
    return result;
}

int BitcoinExchange::date_control(std::string str)
{
    int day = 0;
    int month = 0;
    int year = 0;
    std::istringstream datestream(str);
    std::string str_year,str_month,str_day;
    std::getline(datestream, str_year, '-');
    year = std::atoi(str_year.c_str());
    std::getline(datestream, str_month, '-');
    month = std::atoi(str_month.c_str());
    std::getline(datestream, str_day, '-');
    day = std::atoi(str_day.c_str());
    if(str.length() != 10)
    {
        std::cout << "Error: bad date format => " << str << std::endl;
        return 1;
    }
    if(day < 1 || day > 31)
    {
        std::cout << "Error: bad day => " << str << std::endl;
        return 1;
    }
    if(month < 1 || month > 12)
    {
        std::cout << "Error: bad month => " << str << std::endl;
        return 1;
    }
    if(year < 2009 || year > 2024)
    {
        std::cout << "Error: bad year => " << str << std::endl;
        return 1;
    }
    if(str[4] != '-' || str[7] != '-')
    {
        std::cout << "Error: bad date format => " << str << std::endl;
        return 1;
    }
    if(month == 2 && day > 29)
    {
        std::cout << "Error: bad day => " << str << std::endl;
        return 1;
    }
    if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        std::cout << "Error: bad day => " << str << std::endl;
        return 1;
    }
    if(month == 2 && day == 29 && year % 4 != 0)
    {
        std::cout << "Error: leap year => " << str << std::endl;
        return 1;
    }
    return 0;
}

int BitcoinExchange::value_control(double value)
{
    if(value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }
    else if (value > 1000.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 1;
    }
    return 0;
}
